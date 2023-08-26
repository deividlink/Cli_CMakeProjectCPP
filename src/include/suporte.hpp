#ifndef SUPORTE_HPP
#define SUPORTE_HPP
#include<iostream>
class Suporte{
    public:
    std::string getCaminho(){
        std::string url;
        std::cout << "Digite O Caminho Onde Ficara A Pasta: ";
        std::getline(std::cin,url);
        if(url.size() != 0){
            return url;
        }
        return "vazio";
    }
    std::string getProjectName(){
         std::string nome;
        std::cout << "Digite O Nome Da Pasta Projeto: ";
        std::getline(std::cin,nome);
        if(nome.size() != 0){
            return nome;
        }
        return "vazio";
    }
};
#endif