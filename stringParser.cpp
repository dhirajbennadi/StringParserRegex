/*Reference : https://www.youtube.com/watch?v=9K4N6MO_R1Y*/


#include <iostream>
#include <string>
#include <regex>

using namespace std;

void printVal(string command, int length)
{
    cout << "Command : " << command << " Length: " << length << endl;
}

void PrintMatches(string s, regex reg)
{
    sregex_iterator currentMatch(s.begin() , s.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch)
    {
        smatch match = *currentMatch;
        cout << match.str() << " " << "Length : " <<  match.str().size() << endl;
        currentMatch++;
    }

    cout << endl;
}


int main()
{
    //Command : FirstName_LastName_Age

    // string s = "AAAA25COMMAND4CHECKSUM";

    // smatch matches;
    // std::regex rgx("(AAAA)([0-9])([0-9])(COMMAND)([0-9])(CHECKSUM)");
    // while(std::regex_search(s, matches, rgx))
    // { 
    //   cout << length(matches[4]);

    //   //cout << matches[2].str();
    //   int length1 = stoi(matches[2].str());
    //   int length2 = stoi(matches[3].str());


    //   int totalLength = length1 * 10 + length2;

    //   printVal(matches[4] , totalLength);
    //   s = matches.suffix();
    // }

    string s1 = "The ape is found at the apex aped";
    regex reg1 ("(ape[^ ]?)");
    PrintMatches(s1,reg1);

    string s2 = "Picked the Pickle in a PickleJar";
    regex reg2 ("(Pick([^ ]+)?)");
    PrintMatches(s2,reg2);

    string s3 = "Cat mat rat fat bat";
    regex reg3 ("([a-z]at)");
    PrintMatches(s3,reg3);

    string s4 = "Cat mat rat fat bat";
    regex reg4 ("([C-Fc-f]at)");
    PrintMatches(s4,reg4);

    string s5 = "Cat mat rat fat bat";
    regex reg5 ("([^Cr]at)");
    PrintMatches(s5,reg5);

    string s6 = "Cat mat rat fat bat";
    regex reg6 ("([^Cr]at)");
    string newStrings = regex_replace(s6 , reg6, "*");

    cout << newStrings << endl;


    /*Special Symbols*/
    std::string str7 = "F.B.I. I.R.S. CIA";
    std::regex reg7("([^ ]\\..\\..\\.)");
    PrintMatches(str7,reg7);
 
    return 0;

}