#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " [logisim|rars]\n";
        exit(EXIT_FAILURE);
    }

    std::string choice = argv[1];
    if (choice == "logisim") 
    {
        std::string cmd = "java -jar bin/logisim-evolution-4.1.0dev-all.jar";
        std::cout << "Running Logisim-Evolution...\n";
        std::system(cmd.c_str());
    } 
    else if (choice == "rars") 
    {
        std::string cmd = "java -jar bin/rars.jar";
        std::cout << "Running RARS...\n";
        std::system(cmd.c_str());
    } 
    else 
    {
        std::cerr << "Unknown target: " << choice << "\n";
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
