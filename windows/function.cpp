#include "function.h"


using namespace std;
flutter::EncodableList * FlutterGetNetWorkInfo()
{
    PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
    unsigned long stSize = sizeof(IP_ADAPTER_INFO);
    int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    int netCardNum = 0;
    if (ERROR_BUFFER_OVERFLOW == nRel)
    {
        delete pIpAdapterInfo;
        pIpAdapterInfo = (PIP_ADAPTER_INFO) new BYTE[stSize];
        nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    }
    flutter::EncodableList * networkList = new flutter::EncodableList() ;
    if (ERROR_SUCCESS == nRel)
    {
        while (pIpAdapterInfo)
        {
            flutter::EncodableMap* resMap =new flutter::EncodableMap();
            resMap->insert(std::pair<flutter::EncodableValue,flutter::EncodableValue>("index",++netCardNum));
            flutter::EncodableList* networkInfoList = new flutter::EncodableList() ;
            IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
            do
            {
                flutter::EncodableMap* networkInfoElemMap = new flutter::EncodableMap();
                networkInfoElemMap->insert(std::pair<flutter::EncodableValue,flutter::EncodableValue>("ip",pIpAddrString->IpAddress.String));
                networkInfoElemMap->insert(std::pair<flutter::EncodableValue,flutter::EncodableValue>("ipMask",pIpAddrString->IpMask.String));
                networkInfoElemMap->insert(std::pair<flutter::EncodableValue,flutter::EncodableValue>("gateway",pIpAdapterInfo->GatewayList.IpAddress.String));
                networkInfoList->push_back(*networkInfoElemMap);
                pIpAddrString = pIpAddrString->Next;
            } while (pIpAddrString);
            resMap->insert(std::pair<flutter::EncodableValue,flutter::EncodableValue>("networkInfoList",*networkInfoList));
            networkList->push_back(*resMap);
            pIpAdapterInfo = pIpAdapterInfo->Next;
        }
    }
    if (pIpAdapterInfo)
    {
        delete pIpAdapterInfo;
    }
    return networkList;
}