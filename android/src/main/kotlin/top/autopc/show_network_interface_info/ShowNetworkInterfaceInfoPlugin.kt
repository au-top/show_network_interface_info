package top.autopc.show_network_interface_info

import android.annotation.SuppressLint
import android.app.Activity
import android.content.Context
import android.net.wifi.WifiManager
import android.os.Build
import androidx.annotation.NonNull
import androidx.annotation.RequiresApi

import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import java.net.InetAddress
import java.net.NetworkInterface
import java.net.SocketException
import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

/** ShowNetworkInterfaceInfoPlugin */
class ShowNetworkInterfaceInfoPlugin : FlutterPlugin, MethodCallHandler , ActivityAware {
    private lateinit var channel: MethodChannel
    private lateinit var context: Activity
    override fun onAttachedToEngine(@NonNull flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
        channel = MethodChannel(flutterPluginBinding.binaryMessenger, "show_network_interface_info")
        channel.setMethodCallHandler(this)
    }

    @SuppressLint("HardwareIds")
    @RequiresApi(Build.VERSION_CODES.KITKAT)
    override fun onMethodCall(@NonNull call: MethodCall, @NonNull result: Result) {
        when (call.method) {
            "getPlatformVersion" -> {
                result.success("Android ${android.os.Build.VERSION.RELEASE}")
            }
            "getNetWorkInfo" -> {
                val wifiManage : WifiManager = context.applicationContext.getSystemService(Context.WIFI_SERVICE) as WifiManager;
                val dhcpInfo = wifiManage.dhcpInfo;
                val resMap:HashMap<String,String> = HashMap();
                resMap["gateway"] = intToString(dhcpInfo.gateway);
                resMap["ip"] = intToString(dhcpInfo.ipAddress);
                resMap["ipMask"] = intToString(dhcpInfo.netmask);
                resMap["ipMask"] = "Wifi";
                val networkBox:HashMap<String, Any> = HashMap();
                networkBox["index"]=1;
                networkBox["networkInfoList"]= listOf(resMap);
                /**
                 * transform to
                 [
                    {index: 1, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
                    {index: 2, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.52.70, ipMask: 255.255.0.0}]},
                    {index: 3, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.114.12, ipMask: 255.255.0.0}]},
                    {index: 4, networkInfoList: [{gateway: 172.16.5.254, ip: 172.16.5.107, ipMask: 255.255.255.0}]},
                    {index: 5, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
                    {index: 6, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]}
                 ]
                 * */
                result.success(listOf(networkBox))

            }
            else -> {
                result.notImplemented()
            }
        }
    }

    fun intToString(@NonNull numberData: Int): String {
        val getStartMarkBit:Int=0x000000ff;
        val resList:ArrayList<String> = ArrayList<String>();
        val maxBitLength=4;
        for (i in 1..maxBitLength ){
            resList.add(((numberData shr ((maxBitLength-i)*8)) and getStartMarkBit).toString())
        }
        return resList.reversed().joinToString(".");
    }

    override fun onDetachedFromEngine(@NonNull binding: FlutterPlugin.FlutterPluginBinding) {
        channel.setMethodCallHandler(null)
    }

    override fun onAttachedToActivity(binding: ActivityPluginBinding) {
        context=binding.activity;
    }

    override fun onDetachedFromActivityForConfigChanges() {
        TODO("Not yet implemented")
    }

    override fun onReattachedToActivityForConfigChanges(binding: ActivityPluginBinding) {
        TODO("Not yet implemented")
    }

    override fun onDetachedFromActivity() {
        TODO("Not yet implemented")
    }

}
