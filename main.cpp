#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

const int SIMS = 15;
const int OPS = 4;
const int TYPES = 3;

int main() {
    vector<string> codes;
    ifstream fin("codes.txt");
    string line;

    while (getline(fin, line)) {
        codes.push_back(line);
    }
    fin.close();

long long results[2][OPS][TYPES] = {0};



auto start = chrono::high_resolution_clock::now();

vector<string> v;
for (auto &s : codes) {
    v.push_back(s);
}

auto end = chrono::high_resolution_clock::now();
long long vectorTime = 
    chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    list<string> lst;
    for (const string& code : codes) {
        lst.push_back(code);
    }

    end = chrono::high_resolution_clock::now();
    long long listReadTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    set<string> st;
    for (const string& code : codes) {
        st.insert(code);
    }

    end = chrono::high_resolution_clock::now();
    long long setReadTime =
    chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    vector<string> vecSort = codes;
    start = chrono::high_resolution_clock::now();
    sort(vecSort.begin(), vecSort.end());
    end = chrono::high_resolution_clock::now();
    long long vectorSortTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();



    list<string> listSort(codes.begin(), codes.end());
    start = chrono::high_resolution_clock::now();
    listSort.sort();
    end = chrono::high_resolution_clock::now();
    long long listSortTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    long long setSortTime = -1;

    vector<string> vecInsert = codes;
    start = chrono::high_resolution_clock::now();
    vecInsert.insert(vecInsert.begin() + vecInsert.size() /2 , "TESTCODE");
    end = chrono::high_resolution_clock::now();
    long long vectorInsertTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    list<string> listInsert(codes.begin(), codes.end());
    auto listInsertPos = listInsert.begin();
    advance(listInsertPos, listInsert.size() / 2);
    start = chrono::high_resolution_clock::now();
    listInsert.insert(listInsertPos, "TESTCODE");
    end = chrono::high_resolution_clock::now() ;
    long long listInsertTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    set<string> setInsert(codes.begin(), codes.end());
    start = chrono::high_resolution_clock::now();
    setInsert.insert("TESTCODE");
    end = chrono::high_resolution_clock::now() ;
    long long setInsertTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    vector<string> vecDelete = codes;
    start = chrono::high_resolution_clock::now();
    vecDelete.erase(vecDelete.begin() + vecDelete.size() / 2);
    end = chrono::high_resolution_clock::now();
    long long vectorDeleteTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    list<string> listDelete(codes.begin(), codes.end());
    auto listDeletePos = listDelete.begin();
    advance(listDeletePos, listDelete.size() / 2);
    start = chrono::high_resolution_clock::now();
    listDelete.erase(listDeletePos);
    end = chrono::high_resolution_clock::now();
    long long listDeleteTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    set<string> setDelete(codes.begin(), codes.end());
    auto setDeletePos = setDelete.begin();
    advance(setDeletePos, setDelete.size() / 2);
    start = chrono::high_resolution_clock::now();
    setDelete.erase(setDeletePos);
    end = chrono::high_resolution_clock::now();
    long long setDeleteTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

cout << "Vector Read: "     << vectorTime << endl;
cout << "List read time:   " << listReadTime << " ns" << endl;
cout << "Set read time:    " << setReadTime << " ns" << endl;


cout << "Vector sort time:   " << vectorSortTime << " ns" << endl;
cout << "List sort time:     " << listSortTime << " ns" << endl;
cout << "Set sort time:      " << setSortTime << endl;

cout << "Vector insert time: " << vectorInsertTime << " ns" << endl;
cout << "List insert time:   " << listInsertTime << " ns" << endl;
cout << "Set insert time:    " << setInsertTime << " ns" << endl;

cout << "Vector delete time: " << vectorDeleteTime << " ns" << endl;
cout << "List delete time:   " << listDeleteTime << " ns" << endl;
cout << "Set delete time:    " << setDeleteTime << " ns" << endl;

return 0;
}


