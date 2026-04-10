#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>

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


for (int sim = 0; sim < SIMS; sim++) {
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

results[0][0][0] = vectorTime;
results[0][0][1] = listReadTime;
results[0][0][2] = setReadTime;

results[0][1][0] = vectorSortTime;
results[0][1][1] = listSortTime;
results[0][1][2] = setSortTime;

results[0][2][0] = vectorInsertTime;
results[0][2][1] = listInsertTime;
results[0][2][2] = setInsertTime;

results[0][3][0] = vectorDeleteTime;
results[0][3][1] = listDeleteTime;
results[0][3][2] = setDeleteTime;

for (int op = 0; op < OPS; op++) {
    for (int type = 0; type < TYPES; type++) {
        results[1][op][type] += results[0][op][type];
    }
}
cout << "Completed simulation " << sim + 1 << endl;

long long averages[OPS][TYPES] = {0};

for (int op = 0; op < OPS; op++) {
    for (int type = 0; type < TYPES; type++) {
        averages[op][type] = results[1][op][type] / SIMS;
    }
}




cout << "Number of simulations: " << SIMS << endl;

cout << left
     << setw(12) << "Operation"
     << setw(12) << "Vector"
     << setw(12) << "List"
     << setw(12) << "Set" << endl;

cout << setw(12) << "Read"
     << setw(12) << averages[0][0]
     << setw(12) << averages[0][1]
     << setw(12) << averages[0][2] << endl;

cout << setw(12) << "Sort"
     << setw(12) << averages[1][0]
     << setw(12) << averages[1][1]
     << setw(12) << averages[1][2] << endl;

cout << setw(12) << "Insert"
     << setw(12) << averages[2][0]
     << setw(12) << averages[2][1]
     << setw(12) << averages[2][2] << endl;

cout << setw(12) << "Delete"
     << setw(12) << averages[3][0]
     << setw(12) << averages[3][1]
     << setw(12) << averages[3][2] << endl;

return 0;
}


