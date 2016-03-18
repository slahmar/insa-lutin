#include "es17.h"
#include "../rules.h"

AbstractState::TransitionResult ES17::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(SYM_EXP, RULE_1);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR,S_EOF);
        break;
    }
    return ret;
}

ES17::ES17() :
    AbstractState("ES17")
{

}
