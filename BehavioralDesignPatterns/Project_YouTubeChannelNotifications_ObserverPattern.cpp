/*Let's create a YouTube subscription based notification to all subscribers using observer pattern*/

#include <iostream>
#include <vector>
using namespace std;


// Observer Interface
class Oberver
{
    public:
    virtual void update(string msg) = 0;
};


// Concerete Observer
class Subscribers : public Oberver
{
    public:
    void update(string msg) override
    {
        cout << "NOTIFICATION: A new video is waiting for you titled: " <<"["<<msg <<"]"<< endl << endl;
    }
};

// YouTube Channel being subscribed by a number of observers (subscribers).
class KashifYouTubeChannel
{
    public:
    void registerObserver(Oberver* oberver)
    {
        obervers.push_back(oberver);
    }
    void removeObserver()
    {}
    void getVideoTitle(string msg)
    {
        this->videoTitle = msg;
        notifyObservers();
    }

    private:
    string videoTitle;
    vector<Oberver*> obervers;
    void notifyObservers()
    {
        for(auto* observer : obervers)
        {
            observer->update(videoTitle);
        }
    }
};

int main()
{
    KashifYouTubeChannel kashifChannel;
    
    // Number of Observers/Subscribers
    Subscribers subscriber1;
    Subscribers subscriber2;
    Subscribers subscriber3;
    
    kashifChannel.registerObserver(&subscriber1);
    kashifChannel.registerObserver(&subscriber2);
    kashifChannel.registerObserver(&subscriber3);
    
    kashifChannel.getVideoTitle("Dubai Visit with Family");
    
    
    return 0;
}
