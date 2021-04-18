#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <ostream>
using namespace std;

#include <iostream>
struct MaxHeap
{
private:
    vector<pair<string, int>> arr;

    int Parent(int i)
    {
        return (i - 1 / 2);
    }

    int Left(int i) 
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void heapify_up(int i)
    {
        if (i && arr[Parent(i)].second < arr[i].second)
        {
            swap(arr[i], arr[Parent(i)]);

            heapify_up(Parent(i));
        }
    }
    
public:

    unsigned int size()
    {
        return arr.size();
    }

    void push(pair<string, int> scorePair)
    {
        arr.push_back(scorePair);

        int index = size() - 1;
        heapify_up(index);
    }


};
class Songs
{
public:
    Songs();
    Songs(
        float& _acousticness, string& _artist, float& _dancability, int& _duration , float& _energy, int& _explct, 
        string& _id, float instrumentalness, int& _key, float& _liveness, float& _loudness, int& _mode, /*string& _name*/ 
        int& _popularity, string release_date, float& _speechiness, float& _tempo, float& _valence, int& _year);
    float GetAcousticness();
    string GetArtist();
    float GetDancability();
    int GetDuration();
    float GetEnergy();
    int GetExplct();
    string GetId();
    float GetInstrumentalness();
    int GetKey();
    float GetLiveness();
    float GetLoudness();
    int GetMode();
    string GetName();
    int GetPopularity();
    string GetRelease_date();
    float GetSpeechiness();
    float GetTempo();
    float GetValence();
    int GetYear();

private:
    float acousticness;
    string artist;
    float dancability;
    int duration;
    float energy;
    int explct;
    string id;
    float instrumentalness;
    int key;
    float liveness;
    float loudness;
    int mode;
    string name;
    int popularity;
    string release_date;
    float speechiness;
    float tempo;
    float valence;
    int year;

};
Songs::Songs()
{
    acousticness = 0.0f;
    artist = "";
    dancability = 0.0f;
    duration = 0;
    energy = 0.0f;
    explct = 0;
    id = "";
    instrumentalness = 0.0f;
    key = 0;
    liveness = 0.0f;
    loudness = 0.0f;
    mode = 0;
    name = "";
    popularity = 0;
    release_date;
    speechiness = 0.0f;
    tempo = 0.0f;
    valence = 0.0f;
    year = 0;
}
Songs::Songs(
    float& _acousticness, string& _artist, float& _dancability, int& _duration, float& _energy, int& _explct,
    string& _id, float _instrumentalness, int& _key, float& _liveness, float& _loudness, int& _mode, /*string& _name*/
    int& _popularity, string _release_date, float& _speechiness, float& _tempo, float& _valence, int& _year)
{
    acousticness = _acousticness;
    artist = _artist;
    dancability = _dancability;
    duration = _duration;
    energy = _energy;
    explct = _explct;
    id = _id;
    instrumentalness = _instrumentalness;
    key = _key;
    liveness = _liveness;
    loudness = _loudness;
    mode = _mode;
    //name = _name;
    popularity = _popularity;
    release_date = _release_date;
    speechiness = _speechiness;
    tempo = _tempo;
    valence = _valence;
    year = _year;
}
float Songs::GetAcousticness()
{
    return acousticness;
}
string Songs::GetArtist()
{
    return artist;
}
float Songs::GetDancability()
{
    return dancability;
}
int Songs::GetDuration()
{
    return duration;
}
float Songs::GetEnergy()
{
    return energy;
}
int Songs::GetExplct()
{
    return explct;
}
string Songs::GetId()
{
    return id;
}
float Songs::GetInstrumentalness()
{
    return instrumentalness;
}
int Songs::GetKey()
{
    return key;
}
float Songs::GetLiveness()
{
    return liveness;
}
float Songs::GetLoudness()
{
    return loudness;
}
int Songs::GetMode()
{
    return mode;
}
string Songs::GetName()
{
    return name;
}
int Songs::GetPopularity()
{
    return popularity;
}
string Songs::GetRelease_date()
{
    return release_date;
}
float Songs::GetSpeechiness()
{
    return speechiness;
}
float Songs::GetTempo()
{
    return tempo;
}
float Songs::GetValence()
{
    return valence;
}
int Songs::GetYear()
{
    return year;
}

void GetCSVData(string& filePath, map<string, Songs>& songs, map<string, int>& scores)
{
    ifstream inFile(filePath);
    if (inFile.is_open())
    {
        string lineFromFile;

        unsigned int i = 0;
        while (getline(inFile, lineFromFile))
        {
            istringstream stream(lineFromFile);

            // first take all values in a string and
            // convert to respective data types later
            string tempAcousticness;
            string artist;
            string tempDancability;
            string tempDuration;
            string tempEnergy;
            string tempExplct;
            string id;
            string tempInstrumentalness;
            string tempKey;
            string tempLiveness;
            string tempLoudness;
            string tempMode;
            string name;
            string tempPopularity;
            string release_date;
            string tempSpeechiness;
            string tempTempo;
            string tempValence;
            string tempYear;

            float acousticness;
            float dancability;
            int duration;
            float energy;
            int explct;
            float instrumentalness;
            int key;
            float liveness;
            float loudness;
            int mode;
            int popularity;
            float speechiness;
            float tempo;
            float valence;
            int year;

            getline(stream, tempAcousticness, ',');
            getline(stream, artist, ',');
            getline(stream, tempDancability, ',');
            getline(stream, tempDuration, ',');
            getline(stream, tempEnergy, ',');
            getline(stream, tempExplct, ',');
            getline(stream, id, ',');
            getline(stream, tempInstrumentalness, ',');
            getline(stream, tempKey, ',');
            getline(stream, tempLiveness, ',');
            getline(stream, tempLoudness, ',');
            getline(stream, tempMode, ',');
            getline(stream, name, ',');
            getline(stream, tempPopularity, ',');
            getline(stream, release_date, ',');
            getline(stream, tempSpeechiness, ',');
            getline(stream, tempTempo, ',');
            getline(stream, tempValence, ',');
            getline(stream, tempYear, ',');
            


            if (i != 0)
            {
                acousticness = stof(tempAcousticness);
                dancability = stof(tempDancability);
                duration = stoi(tempDuration);
                energy = stof(tempEnergy);
                explct = stoi(tempExplct);
                instrumentalness = stof(tempInstrumentalness);
                key = stoi(tempKey);
                liveness = stof(tempLiveness);
                loudness = stof(tempLoudness);
                mode = stoi(tempMode);
                popularity = stoi(tempPopularity);
                speechiness = stof(tempSpeechiness);
                tempo = stof(tempTempo);
                valence = stof(tempValence);
                year = stoi(tempYear);

                Songs s(
                    acousticness, artist, dancability, duration, energy, explct, id, instrumentalness, key, liveness, 
                    loudness, mode, popularity, release_date, speechiness, tempo, valence, year);

                songs.emplace(name, s);
                scores.emplace(name, 0);
            }

            
        }
    }
    else
    {
        cout << "file not found" << endl;
    }
}
void applyScores(map<string, Songs> songs, map<string, int> scores, string chosenSong)
{
    map<string, Songs>::iterator songIt;
    map<string, int>::iterator scoresIt;
    map<string, Songs>::iterator it;

    songIt = songs.find(chosenSong);
    scoresIt = scores.find(chosenSong);

    for (it = songs.begin(); it != songs.end(); it++)
    {
        if (it->second.GetAcousticness() - songIt->second.GetAcousticness() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetArtist() == songIt->second.GetArtist())
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetDancability() - songIt->second.GetDancability() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetDuration() - songIt->second.GetDuration() < 100000)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetEnergy() - songIt->second.GetEnergy() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetExplct() == songIt->second.GetExplct())
            scoresIt->second = scoresIt->second + 1;
        
        if (it->second.GetInstrumentalness() - songIt->second.GetInstrumentalness() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetKey() == songIt->second.GetKey())
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetLiveness() - songIt->second.GetLiveness() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetLoudness() - songIt->second.GetLoudness() < 1)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetMode() == songIt->second.GetMode())
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetPopularity() == songIt->second.GetPopularity())
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetSpeechiness() - songIt->second.GetSpeechiness() < .01)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetTempo() - songIt->second.GetTempo() < 10)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetValence() - songIt->second.GetValence() < .1)
            scoresIt->second = scoresIt->second + 1;

        if (it->second.GetYear() == songIt->second.GetYear())
            scoresIt->second = scoresIt->second + 1;
    }
}

int main()
{
    string filePath;
    filePath = "data.csv";
    string chosenSong;
    map<string, Songs> songs;
    map<string, int> scores;
    
    
    GetCSVData(filePath, songs, scores);
    applyScores(songs, scores, chosenSong);
    

}

