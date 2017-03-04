#include <string>

class Tokenizer {
    private:
        bool isInt(std::string s);        
        int tokenize(std::string in);
        bool isQuit(int c);
        std::string tokenized[16];
        
    public: 
        std::string* GetTokens();
};
