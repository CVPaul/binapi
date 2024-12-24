
#ifndef __binapi_marco_h__
#define __binapi_marco_h__

#include <string>

#define UM_API_VER "/fapi/v1/"
#define UM_REST_URL "fapi.binance.com"
#define UM_WSS_URL "fstream.binance.com"
#define GET_UM_REST_ROUTE(path) (UM_API_VER + std::string(path))
#define GET_UM_WSS_ROUTE(path) (UM_API_VER + std::string(path))

#define CM_API_VER "/dapi/v1/"
#define CM_REST_URL "dapi.binance.com"
#define CM_WSS_URL "dstream.binance.com"
#define GET_CM_REST_ROUTE(path) (CM_API_VER + std::string(path))
#define GET_CM_WSS_ROUTE(path) (CM_API_VER + std::string(path))

#define SPOT_API_KEY "/api/v3/"
#define SPOT_REST_URL "api.binance.com"
#define SPOT_WSS_URL "stream.binance.com"
#define GET_SPOT_REST_ROUTE(path) (SPOT_API_VER + std::string(path))
#define GET_SPOT_WSS_ROUTE(path) (SPOT_API_VER + std::string(path))


#endif //  __binapi_marco_h__