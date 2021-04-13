# show_network_interface_info

- cn

在 windows 和 android 平台上提供查看网络信息的能力

---

在 windows  上为查看所有网卡信息
在 android  上为查看wifi网络信息

这些信息都包含 网关 , ip ipMask

如果你有更好的主意或者代码请发起 pr or issues

示例返回结果
```
     [
            {index: 1, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
            {index: 2, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.52.70, ipMask: 255.255.0.0}]},
            {index: 3, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.114.12, ipMask: 255.255.0.0}]},
            {index: 4, networkInfoList: [{gateway: 172.16.5.254, ip: 172.16.5.107, ipMask: 255.255.255.0}]},
            {index: 5, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},
            {index: 6, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]}
    ]   
```



---

- en

show_ network_ interface_ info



Provide the ability to view network information on windows and Android platform



---



To view all network card information on Windows

To view WiFi network information on Android



The information includes gateway, IP, and ipmask



If you have a better idea or code, please launch PR or issues



Examples return results

```

[

{index: 1, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},

{index: 2, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.52.70, ipMask: 255.255.0.0}]},

{index: 3, networkInfoList: [{gateway: 0.0.0.0, ip: 169.254.114.12, ipMask: 255.255.0.0}]},

{index: 4, networkInfoList: [{gateway: 172.16.5.254, ip: 172.16.5.107, ipMask: 255.255.255.0}]},

{index: 5, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]},

{index: 6, networkInfoList: [{gateway: 0.0.0.0, ip: 0.0.0.0, ipMask: 0.0.0.0}]}

]

```