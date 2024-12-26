#ifndef __binapi_marco_h__
#define __binapi_marco_h__

#if TRADE_TYPE == 0
    #define API_VER "/api/v3/"
    #define REST_URL "api.binance.com"
    #define WSS_URL "stream.binance.com"
    #pragma message("Compiling for TRADE_TYPE 0: API_VER = /api/v3/")
#elif TRADE_TYPE == 1
    #define API_VER "/fapi/v1/"
    #define REST_URL "fapi.binance.com"
    #define WSS_URL "fstream.binance.com"
    #pragma message("Compiling for TRADE_TYPE 1: API_VER = /fapi/v1/")
#elif TRADE_TYPE == 2
    #define API_VER "/dapi/v1/"
    #define REST_URL "dapi.binance.com"
    #define WSS_URL "dstream.binance.com"
    #pragma message("Compiling for TRADE_TYPE 2: API_VER = /dapi/v1/")
#else
    #error "Invalid TRDE_TYPE Value!"
#endif

#define GET_REST_ROUTE(path) API_VER path
#define GET_WSS_ROUTE(path) API_VER path

#endif //  __binapi_marco_h__
