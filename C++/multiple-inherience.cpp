#include <bits/stdc++.h>
using namespace std;
class Singer
{
    int sid;
    char sname[20];

public:
    Singer()
    {
    }
    Singer(char sname[], int sid)
    {
        this->sid = sid;
        strcpy(this->sname, sname);
    }
    void show()
    {
        cout << " SINGER DETAILS  " << endl;
        cout << " ID  " << sid;
        cout << "  NAME " << sname;
    }
};
class MusicDir
{
    int mid;
    char mname[20];

public:
    MusicDir()
    {
    }
    MusicDir(char mname[], int mid)
    {
        this->mid = mid;
        strcpy(this->mname, mname);
    }
    void show()
    {
        cout << "Details of music director " << endl;
        cout << " ID " << mid;
        cout << " Name " << mname;
    }
};
class Song : public Singer, public MusicDir
{
    char songname[20];
    int pos;

public:
    Song(char songname[], int pos)
    {
        Singer("Arijit Singh", 123);
        MusicDir("Amit Trivedi", 456);
        this->pos = pos;
        strcpy(this->songname, songname);
    }
    void show()
    {
        Singer::show();
        MusicDir::show();
        cout << "The song name and position is " << endl
             << songname << pos;
    }
};
int main()
{
    Song s("Channa Mereya", 1);

    return 0;
}