#include <iostream>

class Log
{
public:
    enum Level
    {
        Error,
        Warning,
        Info,
    };

private:
    int LevelFlag = Info;

public:
    void setLevel(int Flag)
    {
        this->LevelFlag = Flag;
    }

    void ErrorFunc(const char* message)
    {
        if (LevelFlag == Error)
        {
            std::cout << "[ERROR:] " << message << std::endl;
        }
    }

    void WarningFunc(const char* message)
    {
        if (LevelFlag == Warning)
        {
            std::cout << "[WARNING:] " << message << std::endl;
        }
    }

    void InfoFunc(const char* message)
    {
        if (LevelFlag == Info)
        {
            std::cout << "[INFO:] " << message << std::endl;
        }
    }

};


int main()
{
    Log log;
    log.setLevel(Log::Error);
    log.ErrorFunc("Hello");
    log.WarningFunc("Hello");
    log.InfoFunc("Hello");
}