#include "luckyTicket.h"
using namespace std;
void luckyTicket(){
    LuckyTicket process;
    unsigned start,end,temp;
    while(true){
    cout<<"Range(enter a space): ";
    cin>>start>>end;
	//end of file check
    if(cin.eof())
        break;
	//if you enter a larger number first
    if(start>end){
        temp=start;
        start=end;
        end=temp;
    }
	//start processing the current range
    process.work(process,start,end);
    }
    return;
}
LuckyTicket::LuckyTicket(){}
LuckyTicket::~LuckyTicket(){}
void LuckyTicket::work(LuckyTicket& processArg,unsigned& startArg,unsigned& endArg){
    while(true){
        start=startArg;
        end=endArg;
        output.clear();
        count=0;
        //the test cycle for bit depth and processing method
        if(processArg.check()==false){
            cout<<"error:not corrected range(max 6 symbols), try again"<<endl;
            break;
        }
        cout<<"Chose type lucky ticket:"<<endl;
        cout<<"0-21 only; 1-Mirror only; 2-21&Mirrow; 3-Return: ";
        cin>>key;
		//check the end of the file. If Yes, the completion of the entire program
        if(cin.eof())
            return;
		//check for the correct introduction of the processing key
        if(key!=0&&key!=1&&key!=2&&key!=3){
            cout<<"error:not corrected type, try again"<<endl;
            continue;
        }
	//calling a specific type of processing
        switch(key){
            case TwentyOneOnly:{
                processArg.twentyone();
                break;
            }
            case MirrorOnly:{
                processArg.mirror();
                break;
            }
            case TwentyOneAndMirrow:{
                processArg.full();
                break;
            }
            case Return:{
                count=0;
                output.clear();
                return;
            }
        }
		//output the number of all lucky tickets
        cout<<"Count Lucky Ticket: "<<count<<endl;
        if(count==0)
            continue;
		//if there are lucky tickets, there will be an offer to withdraw them(Yes-No)
        while(true){
            cout<<"Print Numbers Lucky Ticket?(Y/N): ";
            cin>>sym;
            if(cin.eof()){
                return;
            }
            if(sym=='Y'||sym=='y'){
                cout<<"Numbers Lucky Ticket: "<<endl;
                for(i=0;i<output.size();++i)
                    cout<<output[i]<<endl;
                break;
            }
            else if(sym=='N'||sym=='n')
                break;
            else{
                cout<<"invalid answer, try again"<<endl;
                continue;
            }
        }
    }
    return;
}
//processing: the sum of all digits is 21
void LuckyTicket::twentyone(){
    one,two,three,four,five,six=0;
    for(;start<=end;++start){
        one=start/100000;
        two=(start%100000)/10000;
        three=(start%10000)/1000;
        four=(start%1000)/100;
        five=(start%100)/10;
        six=start%10;
        fullsum=one+two+three+four+five+six;
        if(fullsum==21){
            ++count;
            output.push_back(start);
        }
    }
    return;
}
//processing: the sum of the first three digits is equal to the last three
void LuckyTicket::mirror(){
    one,two,three,four,five,six=0;
    for(;start<=end;++start){
        one=start/100000;
        two=(start%100000)/10000;
        three=(start%10000)/1000;
        four=(start%1000)/100;
        five=(start%100)/10;
        six=start%10;
        sum1=one+two+three;
        sum2=four+five+six;
        if(sum1==sum2){
            ++count;
            output.push_back(start);            
        }
    }
    return;
}
//processing: the sum of all digits is 21
// OR 
//the sum of the first three digits is the sum of the last three
void LuckyTicket::full(){
    one,two,three,four,five,six=0;
    for(;start<=end;++start){
        one=start/100000;
        two=(start%100000)/10000;
        three=(start%10000)/1000;
        four=(start%1000)/100;
        five=(start%100)/10;
        six=start%10;
        sum1=one+two+three;
        sum2=four+five+six;
        fullsum=one+two+three+four+five+six;
        if(sum1==sum2||fullsum==21){
            ++count;
            output.push_back(start);            
        }
    }
    return;
}
//check for digit number (max 6)
bool LuckyTicket::check(){
    if(start/100000>9||end/100000>9)
        return false;
    else
        return true;
}