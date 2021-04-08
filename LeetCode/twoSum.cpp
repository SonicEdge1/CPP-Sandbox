#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>

std::vector<int> twoSum(std::vector<int> vals, int target) {
    std::unordered_map<int, int> umap;
    
    for(int i = 0; i < vals.size(); i++){
        int difference = target - vals[i];
        if(umap.find(difference) != umap.end()){
            return std::vector<int> {i, umap.find(difference)->second};
        }
        umap.insert(std::pair<int, int> (vals[i], i));
    }
    throw std::invalid_argument("error, no two sum solution found");
}

int main(){
    std::vector<int> myV = {15,4,2,7,6};
    std::vector<int> soln = twoSum(myV, 9);
    std::cout << "[" << soln[0] << ", " << soln[1] << "]";
    return 0;
}