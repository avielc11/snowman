
#include "snowman.hpp"

const auto TEN = 10;
const auto BIGGER = 44444444;
const auto SMALLER = 11111110;

namespace ariel{
    string basis(int x) {
        if(x == 1) {return " ( : )\n";}
        if(x == 2) {return " (\" \")\n";}
        if(x == 3) {return " (___)\n";}
        if(x == 4) {return " (   )\n";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string torso(int x) {
        if(x == 1) {return "( : )";} 
        if(x == 2) {return "(] [)";}
        if(x == 3) {return "(> <)";}
        if(x == 4) {return "(   )";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string y_hand(int x) {
        if(x == 1) {return ">";}
        if(x == 2) {return "/";}
        if(x == 3) {return "\\";}
        if(x == 4){return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string x_hand(int x) {
        if(x == 1) {return "<";}
        if(x == 2) {return "\\";}
        if(x == 3) {return "/";}
        if(x == 4){return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string eye(int x) {
        if(x == 1) {return ".";}
        if(x == 2) {return "o";}
        if(x == 3) {return "O";}
        if(x == 4) {return "-";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string nose_mouth(int x) {
        if(x == 1) {return ",";}
        if(x == 2) {return ".";}
        if(x == 3) {return "_";}
        if(x == 4) {return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string hat(int x) {
        if(x == 1) {return  " _===_\n";}
        if(x == 2) {return "  ___\n .....\n";}
        if(x == 3) {return "   _\n  /_\\\n";}
        if(x == 4) {return "  ___\n (_*_)\n";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }

    string snowman(int num){
        if(num > BIGGER || num < SMALLER) {
            throw std::out_of_range{"Invalid code '" + to_string(num) + "'"};
        }
        int B = num %TEN;
        num /= TEN;
        int T = num %TEN;
        num /= TEN;
        int Y = num %TEN;
        num /= TEN;
        int X = num %TEN;
        num /= TEN;
        int R = num %TEN;
        num /= TEN;
        int L = num %TEN;
        num /= TEN;
        int N = num %TEN;
        num /= TEN;
        int H = num %TEN; 
        string t1;
        string t2 = "(" + eye(L) + nose_mouth(N) + eye(R) + ")";
        if(Y == 2 && X == 2) {
            t1 = x_hand(X) + t2 + y_hand(Y) + "\n " + torso(T) + " \n";
        }
        else if(X == 2) {
            t1 = x_hand(X) + t2 + " \n " + torso(T) + y_hand(Y) + "\n";
        }
        else if(Y == 2) {
            t1 = " " +  t2 + y_hand(Y) + "\n" + x_hand(X) + torso(T) + " \n";
        }
        else {
            t1 = " " +  t2 + " \n" + x_hand(X) + torso(T) + y_hand(Y) + "\n";
        }
        string ans = hat(H) + t1 + basis(B);
        return ans; 
        
    }
}

