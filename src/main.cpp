#include<iostream>
#include<sys/stat.h>
#include<fstream>
#include "./include/suporte.hpp"

#ifdef _WIN32
#include <direct.h> // Para Windows
#else
#include <sys/types.h>
#include <unistd.h>  // Para sistemas baseados em POSIX, como Linux
#endif


int main(){
    Suporte sp;
    const std::string caminho = sp.getCaminho();
    std::string projeto_nome = sp.getProjectName();
    std::string pasta_bin = "bin";
    std::string pasta_src = "src";
    std::string pasta_include = "include";
    
    if((caminho != "vazio") || (projeto_nome != "vazio") ){
        std::string caminho_completo = caminho + "/" + projeto_nome;
        std::cout << "# Criando Pasta: " << projeto_nome << '\n';

        #ifndef _WIN32
            if(_mkdir(caminho_completo.c_str()) == 0){
        #else
            if(mkdir(caminho_completo.c_str()) == 0){
        #endif 
            std::cout << "Pasta Projeto: " << projeto_nome << " Criada com Sucesso." <<  '\n';
        }else{
            std::cout << "Não foi possível criar a pasta." << std::endl;
        }
        // Pasta bin
        std::string caminho_bin = caminho_completo +"/"+ pasta_bin;
        std::cout << "# Criando Pasta: " << pasta_bin << '\n';
        #ifndef _WIN32
            if(_mkdir(caminho_bin.c_str()) == 0){
        #else
            if(mkdir(caminho_bin.c_str()) == 0){
        #endif 
            std::cout << "Pasta: " << pasta_src << " Criada com Sucesso." <<  '\n';
        }else{
            std::cout << "Não foi possível criar a pasta." << std::endl;
        }
        // Arquivo CMakeLists.txt
        #ifndef _WIN32
            std::ofstream cmake_file((caminho_completo + "\\" + "CMakeLists.txt").string());
        #else
            std::ofstream cmake_file((caminho_completo + "/" + "CMakeLists.txt"));
        #endif
        if(cmake_file.is_open()){
            cmake_file << "cmake_minimum_required(VERSION 3.27)"<< std::endl;
            cmake_file << "project(" << projeto_nome << ")" << std::endl;
            cmake_file << "include_directories(${CMAKE_SOURCE_DIR}/src/include)" << std::endl;
            cmake_file << "set(SOURCES " << std::endl;
            cmake_file << "    src/main.cpp" << std::endl;
            cmake_file << ")" << std::endl;
            cmake_file << "add_executable(" << projeto_nome << " " <<  "${SOURCES})" << std::endl;
            cmake_file << "set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)" << std::endl;
            std::cout << "Arquivo: CMakeLists.txt Criado com Sucesso" << '\n';
        }else{
            std::cout << "Nao Foi Possivel Criar Arquivo: CMakeLists.txt" << '\n';
        }


        // Pasta src
        caminho_completo += "/" + pasta_src; 
        std::cout << "# Criando Pasta: " << pasta_src << '\n';
        #ifndef _WIN32
            if(_mkdir(caminho_completo.c_str()) == 0){
        #else
            if(mkdir(caminho_completo.c_str()) == 0){
        #endif 
            std::cout << "Pasta: " << pasta_src << " Criada com Sucesso." <<  '\n';
        }else{
            std::cout << "Não foi possível criar a pasta." << std::endl;
        }
        // Arquivo main.cpp dentro de src
        #ifndef _WIN32
            std::ofstream codigo_file(caminho_completo +"\\main.cpp");
        #else 
            std::ofstream codigo_file(caminho_completo +"/main.cpp");
        #endif
        if(codigo_file.is_open()){
            codigo_file << "#include<iostream>" << std::endl;
            codigo_file << " " << std::endl;
            codigo_file << "int main(){" << std::endl;
            codigo_file << "    std::cout << \"Hello World\" << \"\\n \" ;" << std::endl;
            codigo_file << "    return 0;" << std::endl;
            codigo_file << "} " << std::endl;
            std::cout << "Arquivo: main.cpp Criado Com Sucesso" << '\n';
        }else{
            std::cout << "Nao Foi Possivel Criar Arquivo: main.cpp" << '\n';
        }


        // Pasta include dentro da Pasta src
        caminho_completo += "/" + pasta_include;
        std::cout << "# Criando Pasta: " << pasta_include << '\n';
        #ifndef _WIN32
            if(_mkdir(caminho_completo.c_str()) == 0){
        #else
            if(mkdir(caminho_completo.c_str()) == 0){
        #endif 
            std::cout << "Pasta: " << pasta_include << " Criada com Sucesso." <<  '\n';
        }else{
            std::cout << "Não foi possível criar a pasta." << std::endl;
        }

        std::cout << "Projeto: " << projeto_nome << " No Caminho: " << caminho + "/" + projeto_nome << '\n';
        
        #ifdef _WIN32
            system("Pause");
        #else
            std::cout << "Digite Enter Para Continuar...";
            std::getchar();
        #endif 

    }

    return 0;
}