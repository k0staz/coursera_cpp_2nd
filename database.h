#pragma once

#include <iostream>
#include "date.h"
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

using namespace std;


class Database{
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& out) const;
    template <typename Func>
    int RemoveIf(Func _pred){
//        int cnt = 0;
//        for (auto i = data.begin(); i != data.end();)
//        {
//            Date day = i->first;
//            auto it_begin = stable_partition(data_last.at(i->first).begin(), data_last.at(i->first).end(), [i, _pred](const auto & s) {
//                bool rez = _pred(i->first, *s);
//                return !rez;
//            });
//            cnt += data_last.at(i->first).end() - it_begin;
//            for (auto it = it_begin; it != data_last.at(i->first).end(); it++)
//            {
//                i->second.erase(*it);
//            }
//            data_last.at(i->first).erase(it_begin, data_last.at(i->first).end());
//            if (i->second.empty())
//            {
//                data_last.erase(i->first);
//                i = data.erase(i);
//            }
//            else {
//                i++;
//            }
//        }
//        return cnt;
    }

    template <typename Func>
    vector<string> FindIf(Func _pred) const{
        vector<string> rez;
        for (const auto& it : data)
        {
            Date day = it.first;
            auto it_find = find_if(it.second.begin(), it.second.end(), [day, _pred](const string & str) {return _pred(day, str); });
            for (const auto& it_ev : it.second)
            {
                if (_pred(it.first, it_ev))
                {
                    stringstream str;
                    str << it.first << " " << it_ev;
                    rez.push_back(str.str());
                }
            }
        }
        return rez;
    }

    string Last(const Date& date) const;

private:
    map<Date, set<string>> data;
    map<Date, vector<string>> data_last;

};

ostream& operator<<(ostream& out, const pair<Date, string>& p);