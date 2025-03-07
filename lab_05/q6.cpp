#include <iostream>
using namespace std;

class Level
{
    private:
        string lvl_name;
        string difficulty;
    
    public:
        Level(){};
        Level(string lvl_name, string difficulty) : lvl_name(lvl_name) , difficulty(difficulty){};

        void setName(string name)
        {
            lvl_name = name;
        }

        void setDifficulty(string d)
        {
            difficulty = d;
        }

        string getName(){return lvl_name;};
        string getDifficulty(){return difficulty;};
};

class VideoGame
{
    private:
        string title;
        string genre;
        Level GameLevels[5];
        int levelIndex;

    public:
        VideoGame()
        {
            for (int i = 0; i < 5; i++)
            {
                i[GameLevels].setName("");
                i[GameLevels].setDifficulty("");
            }

            levelIndex = 0;
        };
        
        VideoGame(string title, string genre) : title(title), genre(genre)
        {
            for (int i = 0; i < 5; i++)
            {
                i[GameLevels].setName("");
                i[GameLevels].setDifficulty("");
            }
            levelIndex = 0;
            
        };

        void setLevels(string name, string diff)
        {
            if (levelIndex < 5)
            {
                GameLevels[levelIndex].setName(name);
                GameLevels[levelIndex++].setDifficulty(diff);
            }
            else
            {
                cout << "MAXIMUM LEVEL LIMIT REACHED" << endl;
            }
        }

        void setTitle(string t){title = t;};
        void setGenre(string g){genre = g;};

        string getGenre(){return genre;};
        string getTitle(){return title;};

        void displayGameDetails()
        {
            cout << this->title << " GAME--" << endl;
            cout << "Genre: " << this->genre << endl;
            cout << "GAME LEVELS----" << endl;
            for (int i = 0; i < levelIndex; i++)
            {
                cout << GameLevels[i].getName() << ": " << GameLevels[i].getDifficulty() << endl;
            }
            cout << "------------------------------"<< endl;
        }
};

int main()
{
    VideoGame game("Mystic Quest", "Adventure");

    game.setLevels("Forest of Secrets", "Easy");
    game.setLevels("Cave of Doom", "Medium");
    game.setLevels("Castle of Shadows", "Hard");

    game.displayGameDetails();

    return 0;
}