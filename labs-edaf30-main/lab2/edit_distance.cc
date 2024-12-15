#include "edit_distance.h"

int Edit_distance::edit_distance(const std::string& p, const std::string& q) {
    int m = p.size();
    int n = q.size();
    for(int i = 0; i <=m; i++){
        distances[i][0] = i;
    }
        for(int j = 0; j <=m; j++){
        distances[0][j] = j;
    }
    for(int i = 0; i <=m; i++){
        for(int j = 0; j <=n; j++){
                if(p[i-1] == q[j-1]){
                    distances[i][j] = distances[i-1][j-1];
                }else{
                    auto temp = distances[i-1][j-1] + 1;
                    if( temp > distances[i-1][j] + 1) temp = distances[i-1][j] + 1;
                    if( temp > distances[i][j-1] + 1) temp = distances[i][j-1] + 1;
                    distances[i][j] = temp;
                }
            }
        }
    return distances[m][n];
}