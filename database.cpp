#include "database.h"

void Database :: Add(const Date& date, const string& event){
    if(data[date].count(event) == 0 && !event.empty()){
        data[date].insert(event);
        data_last[date].push_back(event);
    }
}

void Database ::Print(ostream& out) const {
    for(const auto& d : data){
        for(const string& ev : d.second){
            out << d.first << ' ' << ev << endl;
        }
    }
}

//template <typename Func>
//int Database ::RemoveIf(Func _pred) {
//    int cnt = 0;
//    for (auto i = data.begin(); i != data.end();)
//    {
//        Date day = i->first;
//        auto it_begin = stable_partition(data_last.at(i->first).begin(), data_last.at(i->first).end(), [i, _pred](const auto & s) {
//            bool rez = _pred(i->first, *s);
//            return !rez;
//        });
//        cnt += data_last.at(i->first).end() - it_begin;
//        for (auto it = it_begin; it != data_last.at(i->first).end(); it++)
//        {
//            i->second.erase(*it);
//        }
//        data_last.at(i->first).erase(it_begin, data_last.at(i->first).end());
//        if (i->second.empty())
//        {
//            data_last.erase(i->first);
//            i = data.erase(i);
//        }
//        else {
//            i++;
//        }
//    }
//    return cnt;
//}

//template <typename Func>
//vector<string> Database ::FindIf(Func _pred) const {
//    vector<string> rez;
//    for (const auto& it : data)
//    {
//        Date day = it.first;
//        auto it_find = find_if(it.second.begin(), it.second.end(), [day, _pred](const string & str) {return _pred(day, str); });
//        for (const auto& it_ev : it.second)
//        {
//            if (_pred(it.first, it_ev))
//            {
//                stringstream str;
//                str << it.first << " " << it_ev;
//                rez.push_back(str.str());
//            }
//        }
//    }
//    return rez;
//}

string Database::Last(const Date& date) const
{
    string rez;
    if (data.empty())throw invalid_argument("");
    else
    {
        auto it_rez = data.upper_bound(date);
        auto it_rez1 = data.lower_bound(date);
        if (it_rez1 != it_rez)
        {
            stringstream str;
            str << it_rez1->first << " " << data_last.at(it_rez1->first).back();
            return str.str();
        }
        if (it_rez1 != data.begin())
        {
            it_rez1--;
            if (!it_rez1->second.empty())
            {
                stringstream str;
                str << it_rez1->first << " " << data_last.at(it_rez1->first).back();
                return  str.str();
            }
        }
    }
    throw invalid_argument("");
}

ostream& operator<<(ostream& out, const pair<Date, string>& p)
{
    out << p.first << " " << p.second;
    return out;
}