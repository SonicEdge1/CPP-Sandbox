#include <vector>
#include <iostream>
#include <map>

void vector_maps_iterator(){ 
    std::cout << "You made it to this round;" << std::endl;
}

template <typename T, typename T2>
void vector_maps_iterator(T pair_of_vec_iters, T2 pair_of_map_iters)
{
    std::cout << "\n\n new params last" << std::endl;
    for (pair_of_map_iters.first; pair_of_map_iters.first != pair_of_map_iters.second;){
        if ((*(pair_of_vec_iters.first)).first == (pair_of_map_iters.first)->first){
        std::cout << "pair_of_vec_iters " << (*(pair_of_vec_iters.first)).first <<  " first value = " 
        << (*(pair_of_vec_iters.first)).second[0] 
        << (*(pair_of_vec_iters.first)).second[1] 
        << (*(pair_of_vec_iters.first)).second[2] 
        << std::endl;
        std::cout << "pair_of_map_iters " << (pair_of_map_iters.first)->first << " second value = " << (pair_of_map_iters.first)->second << std::endl;
        }
        else{
            throw std::runtime_error("string names do not match, cannot convert values");
        }
        (pair_of_vec_iters.first)++;
        (pair_of_map_iters.first)++;
    }
}


template <typename T, typename T2, typename... Types>
void vector_maps_iterator(T pair_of_vec_iters, T2 pair_of_map_iters, Types... remaining_args)
{
    std::cout << "\n\n new params original " << std::endl;
    for (pair_of_map_iters.first; pair_of_map_iters.first != pair_of_map_iters.second;){
        if ((*(pair_of_vec_iters.first)).first == (pair_of_map_iters.first)->first){
        std::cout << "pair_of_vec_iters " << (*(pair_of_vec_iters.first)).first <<  " first value = " 
        << (*(pair_of_vec_iters.first)).second[0] 
        << (*(pair_of_vec_iters.first)).second[1] 
        << (*(pair_of_vec_iters.first)).second[2] 
        << std::endl;
        std::cout << "pair_of_map_iters " << (pair_of_map_iters.first)->first << " second value = " << (pair_of_map_iters.first)->second << std::endl;
        }
        else{
            throw std::runtime_error("string names do not match, cannot convert values");
        }
        (pair_of_vec_iters.first)++;
        (pair_of_map_iters.first)++;
    }
    vector_maps_iterator(pair_of_vec_iters, remaining_args...);
}


int main() {
    //initialize the vector of dobles for v2
    std::vector<double> vec1 {1.0, 2.0, 3.0};
    std::vector<double> vec2 {4.0, 5.0, 6.0};
    std::vector<double> vec3 {7.0, 8.0, 9.0};
    std::vector<double> vec4 {7.0, 8.0, 9.0};
    std::vector<double> vec5 {7.0, 8.0, 9.0};
    std::vector<double> vec6 {7.0, 8.0, 9.0};
    std::vector<double> vec7 {7.0, 8.0, 9.0};
    std::vector<double> vec8 {7.0, 8.0, 9.0};
    std::vector<double> vec9 {7.0, 8.0, 9.0};
    std::vector<double> vec10 {7.0, 8.0, 9.0};
    std::vector<double> vec11 {7.0, 8.0, 9.0};
    std::vector<double> vec12 {7.0, 8.0, 9.0};
    std::vector<double> vec13 {7.0, 8.0, 9.0};
    std::vector<double> vec14 {7.0, 8.0, 9.0};
    std::vector<double> vec15 {1.0, 2.0, 3.0};

    //this will be our vecotr of values to loop through
    std::vector<std::pair<std::string, std::vector<double>>> v2 {make_pair("string1", vec1)};
    v2.push_back(make_pair("string2", vec2));
    v2.push_back(make_pair("string3", vec3));
    v2.push_back(make_pair("string4", vec4));
    v2.push_back(make_pair("string5", vec5));
    v2.push_back(make_pair("string6", vec6));
    v2.push_back(make_pair("string7", vec7));
    v2.push_back(make_pair("string8", vec8));
    v2.push_back(make_pair("string9", vec9));
    v2.push_back(make_pair("string10", vec10));
    v2.push_back(make_pair("string11", vec11));
    v2.push_back(make_pair("string12", vec12));
    v2.push_back(make_pair("string13", vec13));
    v2.push_back(make_pair("string14", vec14));
    v2.push_back(make_pair("string15", vec15));
    v2.push_back(make_pair("string10", vec10));
    v2.push_back(make_pair("string11", vec11));
    v2.push_back(make_pair("string12", vec12));
    v2.push_back(make_pair("string13", vec13));
    v2.push_back(make_pair("string14", vec14));
    v2.push_back(make_pair("string15", vec15));


    //these are three proof of concept maps to show that 
    //we can use maps of different types
    std::vector<float> vec_ref {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<float> & vec_ref_actual = vec_ref;
    std::map<std::string, float&> v1; //= {{"string1", vec_ref[0]}, {"string2", vec_ref[1]}};
    for (auto& i : vec_ref_actual){
     v1.insert(std::pair<std::string, float&>("string" + std::to_string(static_cast<int>(i)), i));
    }

    std::vector<double> vec_ref3 {10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
    std::vector<double> & vec_ref_actual3 = vec_ref3;
    std::map<std::string, double&> v3; //= {{"string1", vec_ref[0]}, {"string2", vec_ref[1]}};
    for (auto& i : vec_ref_actual3){
        v3.insert(std::pair<std::string, double&>("string" + std::to_string(static_cast<int>(i)), i));
    }

    std::vector<double> vec_ref4 {10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
    std::vector<double> & vec_ref_actual4 = vec_ref4;
    std::map<std::string, double&> v4; //= {{"string1", vec_ref[0]}, {"string2", vec_ref[1]}};
    for (auto& i : vec_ref_actual4){
        v4.insert(std::pair<std::string, double&>("string" + std::to_string(static_cast<int>(i)), i));
    }

    //make the iterators for the vectors and maps
    std::map<std::string, float&>::iterator it1 = v1.begin();
    std::vector<std::pair<std::string, std::vector<double>>>::iterator it2 = v2.begin();
    std::map<std::string, double&>::iterator it = v3.begin();
    std::map<std::string, double&>::iterator it4 = v4.begin();

    //store the begins and ends in a pair so that the parse object always takes the beginning and end
    //so that you always pass in a pair of iterators so the object type doesn't change so we can 
    //properly use the templates
    std::pair<std::map<std::string, float&>::iterator , std::map<std::string, float&>::iterator> p1 = make_pair(it1, v1.end());
    std::pair< std::vector<std::pair<std::string, std::vector<double>>>::iterator , std::vector<std::pair<std::string, std::vector<double>>>::iterator> p2 = make_pair(it2, v2.end());
    std::pair< std::map<std::string, double&>::iterator, std::map<std::string, double&>::iterator> p3 = make_pair(it, v3.end());
    std::pair< std::map<std::string, double&>::iterator, std::map<std::string, double&>::iterator> p4 = make_pair(it4, v4.end());

    vector_maps_iterator(p2, p1, p3, p4);
    return 0;
}

