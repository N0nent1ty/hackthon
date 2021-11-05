#include <vector>
#include <iostream>
#include <string>


using namespace std;


int main(int argc, char** argv){

    size_t _n =126;
    vector<string> _curGammaV(3);

    for(size_t i = 0; i < _n; i++){
        char ch = (char)i;
        _curGammaV[0] += ch;
        _curGammaV[1] += ch;
        _curGammaV[2] += ch;
    }
    for(auto i : _curGammaV){
        cout<< i<<endl;
    }

    auto s=_curGammaV;
    vector<vector<vector<bool> > > _isBefore;
    for(size_t i = 0; i < _n; i++){
        for(size_t j = 0; j < i; j++){
            if(i == j)
                continue;
            char chI = (char)i;
            char chJ = (char)j;
            for(size_t k = 0; k < 3; k++){
                size_t indexI = s[k].find(chI);
                size_t indexJ = s[k].find(chJ);
                if(indexI < indexJ){
                    _isBefore[i][j][k] = true;
                }
                else if(indexI > indexJ){
                    _isBefore[i][j][k] = false;
                }
                else{
                    cout << "ERROR! duplicate objects" << endl;
                }
            }
        }
    }
    for (auto i:_isBefore){
        for(auto j: i){
            for(auto k:j){
                cout<<k;
            }
            cout<<endl;
        }
        cout<<"===================="<<endl;
    }
    return 0;
}