#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <queue>
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

    string top()
    {
        if (size() != 0)
        {
            return arr[0].first;
        }

    }

    string at(int i)
    {
        return arr[i].first;
    }


};
class Node {
public:
    int score;

    Node *left;
    Node *right;

    Node(){
        score = 0;
        left = NULL;
        right = NULL;
    };
    Node(int _score){
        score = _score;
        left = NULL;
        right = NULL;
    };
    Node(int _score, Node* _left, Node* _right){
        score = _score;
        left = _left;
        right = _right;
    };
};

class Tree {
private:
    int index = 0;
public:
    Node* insert(Node* root, int score);
    Node* successor(Node* root);
    Node* deleteScore(Node* root, int score);
    Node* findMaxScore(Node* root);
};

Node* Tree::insert(Node* root, int score) {

    if(root == NULL){
        return new Node(score);
    }

    if(score < root->score){
        root->left = insert(root->left, score);
    }
    else{
        root->right = insert(root->right, score);
    }

    return root;
}

Node* Tree::successor(Node* root) {
    if(root==NULL){
        return NULL;
    }
    Node* node = root;
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

Node* Tree::deleteScore(Node* root, int score) {
    if(root == NULL){
        return root;
    }

    if(score < root->score ){
        root->left = deleteScore(root->left, score);
    }

    else if(score > root->score){
        root->right = deleteScore(root->right, score);
    }

    else{
        if(root->left == NULL && root->right == NULL) {
            Node* node = nullptr;
            return node;
        }
        if(root->left == NULL){
            Node* node = root->right;
            delete root;
            return node;
        }
        if(root->right == NULL){
            Node* node = root->left;
            delete root;
            return node;
        }
        Node* temp = successor(root->right);
        root->score = temp->score;
        root->right = deleteScore(root->right, temp->score);
    }
    return root;
}

Node* Tree::findMaxScore(Node* root){

    if(root == NULL){
        return NULL;
    }
    else{
        findMaxScore(root->right);
        if(index++ < 10){
            cout << root->score << " ";
        }
        findMaxScore(root->left);
    }
}

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

void MakeHeap(map<string, int>& scores, MaxHeap& mh)
{
    
    map<string, int>::iterator it;
    for (it = scores.begin(); it != scores.end(); it++)
    {
        mh.push(make_pair(it->first, it->second));
    }
}
void TopSongs(MaxHeap& mh, map<string, Songs>& songs, int listSize)
{
    map<string, Songs>::iterator it;
    queue<pair<string,Songs>> q;
    string top = mh.top();
    int left;
    int right;
    int index = 0;
    it = songs.find(top);
    q.push(make_pair(it->first, it->second));
    pair<string, Songs> currentSong = q.front();
    int i = 1;
    while (!q.empty() || i != listSize)
    {
        q.pop();
        cout << currentSong.first << endl;
        currentSong = q.front();
        
        i++;
        left = 2 * index + 1;
        it = songs.find(mh.at(left));
        q.push(make_pair(it->first, it->second));
        
        i++;
        right = 2 * index + 2;
        it = songs.find(mh.at(right));
        q.push(make_pair(it->first, it->second));

        
    }
        

          
    
    

}

int main()
{
    MaxHeap mh;
    string filePath;
    filePath = "data.csv";
    string chosenSong;
    int listSize = 10;
    
    map<string, Songs> songs;
    map<string, int> scores;
    int number;


    cout << "Enter number 1-10 for example playlist" << endl;
    cin >> number;

    switch(number){
        case 1:
            chosenSong = "Keep A Song In Your Soul";
            break;
        case 2:
            chosenSong = "I Put A Spell On You";
            break;
        case 3:
            chosenSong = "#NOHOOK";
            break;
        case 4:
            chosenSong = "Chicago Breakdown";
            break;
        case 5:
            chosenSong = "90210 (feat. Kacy Hill)";
            break;
        case 6:
            chosenSong = "Devil Town";
            break;
        case 7:
            chosenSong = "Fire on the Mountain - Live at Soldier Field, Chicago, IL 7/3/2015";
            break;
        case 8:
            chosenSong = "Trouble";
            break;
        case 9:
            chosenSong = "Ease My Mind";
            break;
        case 10:
            chosenSong = "Best Friend";
            break;
    }



    GetCSVData(filePath, songs, scores);
    applyScores(songs, scores, chosenSong);
    MakeHeap(scores, mh);
    TopSongs(mh, songs, listSize);

}
