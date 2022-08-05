//
// Created by fang on 2022/8/2.
//


#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "bilibili.h"
#include "bilibili/util/md5.hpp"
#include "curl/curl.h"
#include "bilibili/util/http.hpp"

namespace bilibili {


    void BilibiliClient::search_video(const std::string &key, const std::string &search_type,
                             uint index, const std::string &order,
                             const std::function<void(SearchResult)> &callback,
                             const ErrorCallback &error){
        HTTP::getResultAsync<SearchResult>(Api::Search,
                                           {{"__refresh__", "true"},
                                            {"_extra", ""},
                                            {"context", ""},
                                            {"page", std::to_string(index)},
                                            {"page_size", "20"},
                                            {"order", order},
                                            {"duration", ""},
                                            {"from_source", ""},
                                            {"from_spmid", "333.337"},
                                            {"platform", "pc"},
                                            {"device", "mac"},
                                            {"highlight", "1"},
                                            {"single_column", "0"},
                                            {"keyword", key},
                                            {"category_id", ""},
                                            {"search_type", search_type},
                                            {"dynamic_offset", "0"}},
                                           [callback](auto data){
                                               callback(data);
                                           }, error);
    }

}