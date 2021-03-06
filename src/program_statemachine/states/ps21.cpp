#include "ps21.h"
#include "ps22.h"
#include "../rules.h"

AbstractState::TransitionResult PS21::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_V:///< ','
            machine.Reduce(SYM_LC, RULE_9);
            ret = AbstractState::REDUCED;
            break;
        case S_PV:///< ';'
            machine.Reduce(SYM_LC, RULE_9);
            ret = AbstractState::REDUCED;
            break;
        case S_LC:///< liste de constantes
            machine.PileUp(symbol, new PS22());
            ret = AbstractState::PILED_UP;
            break;
        default:
            SYNTAX_ERROR_HANDLER(SYM_PV)
            break;
    }
    return ret;

}

PS21::PS21() :
    AbstractState("PS21")
{

}
