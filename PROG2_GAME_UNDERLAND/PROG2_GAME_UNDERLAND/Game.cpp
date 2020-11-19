#include "Game.h"

//Window configuration
void Game::initWindow()
{
    //Read video config from .ini file
    std::ifstream ifs("Config/window.ini");

    //Set Defaults values
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framrate_limit = 144;

    //Asign .ini values
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framrate_limit;
    }

    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framrate_limit);
}

//Mapping keys
void Game::initKeys()
{
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}   

//Constructor
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

//Destructor
Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//Functions
void Game::endApplication()
{
    std::cout << "Ending Application." << "\n";
}

void Game::updateDt()
{
    //Updates the delta time variable with the time it takes to update and render one frame
    //This prevents engine speed tied to fps 
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }

    //End
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //Render
    if (!this->states.empty())
        this->states.top()->render();
    
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
