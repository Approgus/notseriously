//by Ilya Antipov 2018 Nizhny Novgorod
#ifndef LUCKYTICKET_H
#define LUCKYTICKET_H
#include <vector>
#include <iostream>
//container for withdrawal of all lucky tickets
typedef std::vector<unsigned>outputType;
//listing possible operations
enum key{TwentyOneOnly,MirrorOnly,TwentyOneAndMirrow,Return};
class LuckyTicket{
public:
    LuckyTicket();
    ~LuckyTicket();
    void work(LuckyTicket& processArg,unsigned& startArg,unsigned& endArg);
private:
    outputType output;//lucky tickets container
    unsigned start,end;//a range of tickets
    unsigned count;//number of lucky tickets in the range
    unsigned fullsum,sum1,sum2;//variables for ticket processing
    unsigned key;//processing type control variable
    unsigned i;//variable display cycle of happy tickets
    char sym;//variable Yes-No
    //ticket numbers
    unsigned one,two,three,four,five,six;
    //3 types of search for happy tickets+check on the bit
    void twentyone();
    void mirror();
    void full();
    bool check();
};
void luckyTicket();//function definition
#endif