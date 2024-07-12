#include "train.h"
#include "network.h"
#include "dataload.h"
#include "arch.h"

void train([[maybe_unused]]Network &network) {
    std::cout << "now this is training i guess?" << std::endl;
    /*
        GENERAL PLAN:
        Load batch into memory
        get first position
        stuff it into network
        inference
        backpropogate with error to get gradients
        add gradient to a sum or something idk
        if(batch isn't done) goto "get first position"
        apply the average gradient on that batch (* lr i think?!?!?!)
        if(!done) goto "load batch into memory"

        and I know this is "pure" SGD, however I don't know anything about other methods yet, I'll probably try some stuff with momentum and like adamW i think it's called sometime soon
        it's simpler for me to do this for now, i thnk
    */
}
