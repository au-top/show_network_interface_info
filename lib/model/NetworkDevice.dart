class NetworkDevice {
  late int index;
  late List<NetworkInfo> networkInfoList;

  NetworkDevice.fromMap(Map mapContent) {
    this.index = mapContent["index"];
    this.networkInfoList = (mapContent["networkInfoList"] as List<Object?>)
        .map((e) => NetworkInfo.fromMap(e as Map))
        .toList();
  }
}

class NetworkInfo {
  late String gateway;
  late String ip;
  late String ipMask;
  late String name;
  NetworkInfo.fromMap(Map mapContent) {
    this.gateway = mapContent["gateway"];
    this.ip = mapContent["ip"];
    this.ipMask = mapContent["ipMask"];
    this.name = mapContent["name"];
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