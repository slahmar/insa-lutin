#include "ps11.h"
#include "ps12.h"

AbstractState::TransitionResult PS11::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< 'id'
        // on ajoute la nouvelle variable
        if(!machine.GetDataMap().AppendVar(symbol.buf))
			machine.Unexpected(AbstractStateMachine::WARNING,machine.GetDataMap().GetLastError());

		machine.PileUp(symbol, new PS12());
        ret = AbstractState::PILED_UP;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_ID)
        break;
    }
    return ret;

}

PS11::PS11() :
    AbstractState("PS11")
{

}
