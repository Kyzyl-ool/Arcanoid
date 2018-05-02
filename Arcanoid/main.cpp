#include "PhysicsManager.cpp"
#include "GraphicsManager.cpp"


int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arcanoid");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    //Creating main game objects
    GraphicsManager GManager(&window);
    PhysicsManager  PManager;
    
    Background b(0);
    Support support;
    
    
    //Loading all game objects to game manager's array
    GManager.AddSprite(&b);
    GManager.AddSprite(&support);
    PManager.AddGameObject(&support);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {
                            window.close();
                            break;
                        }
                        case sf::Keyboard::Left:
                        {
                            support.setVelocity(-20);
                            break;
                        }
                        case sf::Keyboard::Right:
                        {
                            support.setVelocity(20);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Left:
                        case sf::Keyboard::Right:
                        {
                            support.reduceVelocity();
                            break;
                        }
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }
        
        support.dump();
        
        // Clear screen
        window.clear();
        GManager.DrawAllObjects();
        PManager.UpdateAllObjects();
        // Update the window
        window.display();
    }
    return 0;
}
