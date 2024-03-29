#include "Factory.h"
// You may put your include statements here
#include "Arena.h"
using namespace std;

/*
 *	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
 */
//=======================================================================================
/*
 *	createArena()
 *
 *	Creates and returns an object whose class extends ArenaInterface.
 *	This should be an object of a class you have created.
 *
 *	Example: If you made a class called "Arena", you might say, "return new Arena();".
 */
ArenaInterface* Factory::createArena()
{
    return new Arena();
}
//=======================================================================================
