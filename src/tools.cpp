// ----------------------------------------------------------------------------
//                              Apache License
//                        Version 2.0, January 2004
//                     http://www.apache.org/licenses/
//
// This file is part of binapi(https://github.com/niXman/binapi)
// project.
//
// Copyright (c) 2019-2021 niXman (github dot nixman dog pm.me). All
// rights reserved.
// ----------------------------------------------------------------------------

#include <cstdint>
#include <sstream>
#include <iomanip>

#include <binapi/tools.h>
#include <binapi/pairslist.hpp>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/trim.hpp>

namespace binapi {

/*************************************************************************************************/

std::size_t num_fractions_from_double(const double &v) {
    std::size_t n = 0u;
    for (double r = v; r < 1; ++n)
        r *= 10;
    return n;
}

double adjust_to_step(const double &v, const double &s, bool increase) {
    std::int64_t step1 = (v * 100000000);
    std::int64_t step2 = step1 % static_cast<std::int64_t>(s * 100000000);
    std::int64_t step3 = step1 - step2;
    double       res   = double(step3) / 100000000;
    res += (increase ? s : 0.0);

    return res;
}

/*************************************************************************************************/

std::vector<std::string> split_string(const std::string &str, const char *sep) {
    std::vector<std::string> res{};

    boost::algorithm::split(res, str, boost::is_any_of(sep));
    for (auto &it : res) {
        boost::algorithm::trim(it);
    }

    return res;
}

std::string join_string(const std::vector<std::string> &vec, const char *sep) {
    return boost::algorithm::join(vec, sep);
}

std::string format_double(double value, int precision, std::ios_base::fmtflags flags) {
    std::ostringstream oss;
    oss.setf(flags);
    oss << std::setprecision(precision) << value;
    return oss.str();
}

/*************************************************************************************************/

double percents_diff(const double &a, const double &b) {
    if (a == b) return 0;

    return ((b - a) / a) * 100;
}

double percents_add(const double &v, const double &p) {
    if (p == 0) return v;

    return v + ((v / 100) * p);
}

double percents_sub(const double &v, const double &p) {
    if (p == 0) return v;

    return v - ((v / 100) * p);
}

double percents_val_by_percent(const double &v, const double &p) { return (v / 100) * p; }

/*************************************************************************************************/

bool is_my_orderid(const char *client_order_id) {
    const char *start = client_order_id;
    const char *p     = std::strchr(client_order_id, '-');
    if (!p) { return false; }

#define __STRCMP_CSTR(x) std::strncmp(start, x, sizeof(x) - 1) == 0

    const auto len = p - start;
    switch (len) {
        case 3:
            return __STRCMP_CSTR("FIX");
        case 4:
            return __STRCMP_CSTR("SRSI");
        case 5:
            return __STRCMP_CSTR("AROON") || __STRCMP_CSTR("SLOSS") || __STRCMP_CSTR("TAKEP");
        case 6:
            return __STRCMP_CSTR("SRSI_U") || __STRCMP_CSTR("SRSI_D") || __STRCMP_CSTR("SRSI_C");
        case 7:
            return __STRCMP_CSTR("HOLEBUY") || __STRCMP_CSTR("INASELL");
        case 8:
            return __STRCMP_CSTR("CYCLEBUY") || __STRCMP_CSTR("SPREDBUY") || __STRCMP_CSTR("SLOSSBUY");
        default:
            return false;
    }

#undef __STRCMP_CSTR

    return false;
}

bool is_my_orderid(const std::string &client_order_id) { return is_my_orderid(client_order_id.c_str()); }

/*************************************************************************************************/

}  // namespace binapi
