
import 'dart:async';

import 'package:flutter/services.dart';

class ShowNetworkInterfaceInfo {

  static const MethodChannel _channel =
      const MethodChannel('show_network_interface_info');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  static Future<void> get getNetWorkInfo async {
    final getNetWorkInfo = await _channel.invokeMethod('getNetWorkInfo');
    print(getNetWorkInfo);
    return null;
  }

}

/**
    [
      {index: 1, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
      {index: 2, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.52.70, ipMask: 255.255.0.0}]},
      {index: 3, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.114.12, ipMask: 255.255.0.0}]},
      {index: 4, networkInfoList: [{gateway: 172.16.5.254, ip: 172.16.5.107, ipMask: 255.255.255.0}]},
      {index: 5, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
      {index: 6, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]}
    ]
*/