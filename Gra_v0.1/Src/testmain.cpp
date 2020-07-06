#include "..\Inc\Level.hpp"
//wykomentowane, bo się z main.cpp kłóciło

int main(){
    //Generating test level
    Level l(true);

    l.Constructions.push_back(Construction(9, 32, 2));
	l.Constructions.push_back(Construction(34, 32, 2));
	l.Constructions.push_back(Construction(59, 32, 2));

    //std::cout << l.Enemies.size() << "\n";
    l.saveF("D:\\Studia\\reposy\\level3.txt");

    return 0;
}

