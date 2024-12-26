
// ----------------------------------------------------------------------------
//                              Apache License
//                        Version 2.0, January 2004
//                     http://www.apache.org/licenses/
//
// This file is part of binapi(https://github.com/niXman/binapi) project.
//
// Copyright (c) 2019-2021 niXman (github dot nixman dog pm.me). All rights reserved.
// ----------------------------------------------------------------------------

#ifndef __binapi__tools_hpp
#define __binapi__tools_hpp

#include <ios>
#include <string>
#include <vector>

namespace binapi {

/*************************************************************************************************/

std::size_t num_fractions_from_double(const double &v);

double adjust_to_step(const double &v, const double &s, bool increase = false);

std::vector<std::string> split_string(const std::string &str, const char *sep);
std::string join_string(const std::vector<std::string> &vec, const char *sep);
std::string format_double(double value, int precision, std::ios_base::fmtflags flags);

/*************************************************************************************************/

double percents_diff(const double &a, const double &b);
double percents_add(const double &v, const double &p);
double percents_sub(const double &v, const double &p);
double percents_val_by_percent(const double &v, const double &p);

/*************************************************************************************************/

bool is_my_orderid(const std::string &client_order_id);
bool is_my_orderid(const char *client_order_id);

/*************************************************************************************************/

} // ns binapi

#endif // __binapi__tools_hpp
