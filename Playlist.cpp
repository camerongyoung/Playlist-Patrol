#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <ostream>
#include <list>


using namespace std;

#include <chrono>
#include <iostream>
class Node
{
public:
    int score;
    string name;
    vector<string> names;
    Node* left;
    Node* right;
    int height;
};
Node* newNode(int score, string name)
{
    Node* currentNode = new Node();
    currentNode = currentNode;
    currentNode->score = score;
    currentNode->names.push_back(name);
    currentNode->height = 1;

    return currentNode;
}
int height(Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
Node* rotateRight(Node* node)
{
    Node* newRoot = node->left;
    Node* swingNode = newRoot->right;

    newRoot->right = node;
    node->left = swingNode;

    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}
Node* rotateLeft(Node* node)
{
    Node* newRoot = node->right;
    Node* swingNode = newRoot->left;

    newRoot->left = node;
    node->right = swingNode;

    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}
int max(int left, int right)
{
    if (left > right)
        return left;
    else
        return right;
}
int getBalance(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}
Node* insert(Node* root, int score, string name)
{

    if (root == NULL)
    {
        return newNode(score, name);
    }

    if (score < root->score)
        root->left = insert(root->left, score, name);
    else if (score > root->score)
        root->right = insert(root->right, score, name);
    else if (score == root->score)
    {
        root->names.push_back(name);
    }
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    //Left Left
    if (balance > 1 && score < root->left->score)
    {
        return rotateRight(root);
    }

    // Right Right
    if (balance < -1 && score > root->right->score)
    {
        return rotateLeft(root);
    }

    //Left Right
    if (balance > 1 && score > root->left->score)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && score < root->right->score)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
void findTopTenAVL(Node* root, int& i, vector<pair<string, int>>& top10) {
    if (root == NULL) {
        return;
    }
    else {
        if(root->right != NULL) {
            findTopTenAVL(root->right, i, top10);
        }
        for(int j = 0; j < root->names.size(); j++) {
            if (top10.size() == 11) {
                return;
            }
            i++;
            pair<string, int> pushedPair;
            pushedPair.first = root->names[j];
            pushedPair.second = root->score;
            top10.push_back(pushedPair);
        }
        if(root->left != NULL) {
            findTopTenAVL(root->left, i, top10);
        }

    }
}

void printTopTenAVL(vector<pair<string, int>>& top10) {
    cout << "Song used as Algorithm Input: " << endl;
    cout << "Name: " << top10[0].first << "; Score: " << top10[0].second << endl << endl;
    cout << "Current Data Structure: AVL Tree" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Top 10 Playlist: " << endl;
    for(int j = 1; j < top10.size(); j++) {
        cout << j << ". Name: " << top10[j].first << "; Score: " << top10[j].second << endl;
    }
    return;
}

struct MaxHeap
{
private:
    vector<pair<string, int>> arr;

    int Parent(int i)
    {
        //cout << i << endl;
        int nI = (i - 1) / 2;
        //cout << nI << endl;
        return nI;
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
        int p = Parent(i);
        //cout << p << endl;
        if (arr[p].second < arr[i].second)
        {
            swap(arr[i], arr[p]);

            heapify_up(p);
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
class Songs
{
public:
    Songs();
    Songs(
            float& _acousticness, string& _artist, float& _dancability, int& _duration, float& _energy, int& _explct,
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
    fstream inFile("data.csv");
    //cout << filePath;

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
                /*if (name == "Taro Yard Slaughter House")
                {
                    cout << "stop" << endl;
                }*/
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

                //cout << name << endl;
                Songs s(
                        acousticness, artist, dancability, duration, energy, explct, id, instrumentalness, key, liveness,
                        loudness, mode, popularity, release_date, speechiness, tempo, valence, year);

                songs.emplace(name, s);
                //cout << name << endl;
                scores.emplace(name, 0);
            }

            i++;
        }
    }
    else
    {
        cout << "file not found" << endl;
    }
}
void applyScores(map<string, Songs>& songs, map<string, int>& scores, string chosenSong)
{
    map<string, Songs>::iterator songIt;
    map<string, int>::iterator scoresIt;
    map<string, Songs>::iterator it;

    songIt = songs.find(chosenSong);


    for (it = songs.begin(); it != songs.end(); it++)
    {
        scoresIt = scores.find(it->first);
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

        //cout << "Song: " <<scoresIt->first << " " << "Score: " <<scoresIt->second << endl;
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
vector<pair<string, Songs>> TopSongs(MaxHeap& mh, map<string, Songs>& songs, int listSize)
{
    map<string, Songs>::iterator it;
    vector<pair<string, Songs>> playlist;
    string top = mh.top();
    int i = 1;



    //q.push(make_pair(it->first, it->second));
    //pair<string, Songs> currentSong = q.front();

    while (i < listSize + 1)
    {
        //q.pop();
        //cout << currentSong.first << endl;
        //currentSong = q.front();

        it = songs.find(mh.at(i));
        i++;
        playlist.push_back(make_pair(it->first, it->second));

        //cout << it->first << endl;

        it = songs.find(mh.at(i));
        i++;
        playlist.push_back(make_pair(it->first, it->second));

        //cout << it->first << endl;



    }
    return playlist;
}
void printTopTenHeap(vector<pair<string, Songs>> &playlist, map<string, int> &scores) {
    cout << "Current Data Structure: Max Heap" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Top 10 Playlist: " << endl;
    for(int j = 0; j < playlist.size(); j++) {
        cout << j+1 << ". Name: " << playlist[j].first << "; Score: " << scores[playlist[j].first] << endl;
    }
    return;
}
Node* insertScoresInTree(Node* root, map<string, int> scores)
{
    map<string, int>::iterator it;

    for (it = scores.begin(); it != scores.end(); it++)
    {
        //cout << "Size: " << tree.size(root) << endl;
        root = insert(root, it->second, it->first);

    }
    return root;
}
int main()
{
    MaxHeap mh;
    string filePath;
    filePath = "data.csv";
    string chosenSong;
    int listSize = 10;
    Node* root = NULL;
    int i = 0;


    map<string, Songs> songs;
    map<string, int> scores;
    int number;


    cout << "Enter number 1-10 for example playlist" << endl;
    cin >> number;

    switch (number) {
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
    auto start = std::chrono::high_resolution_clock::now();
    root = insertScoresInTree(root, scores);
    vector<pair<string, int>> top10AVL;
    findTopTenAVL(root, i, top10AVL);
    auto finish = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(finish-start);
    cout << "[AVL Tree] insert done: " << endl;
    cout << "Task performed in " << duration.count() << " microseconds." << endl;
    start = std::chrono::high_resolution_clock::now();
    MakeHeap(scores, mh);
    vector<pair<string, Songs>> playlist = TopSongs(mh, songs, listSize);
    finish = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(finish-start);
    cout << "[Max Heap] insert done: " << endl;
    cout << "Task performed in " << duration.count() << " microseconds." << endl;
    cout << endl;

    printTopTenAVL(top10AVL);
    cout << endl;
    printTopTenHeap(playlist, scores);

}
