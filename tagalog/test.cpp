#include "tagalog.hpp"
#include <iostream>

ginagamit pangalangpatlang std;

intidyer main() {
    clabas << "Kamusta mundo!" << taposlinya;

    karakter c;

    clabas << "Magtala ng isang karakter: ";
    cpasok >> c;

    kung (c == 'a') {
        clabas << "Pinili mo ang letrang a" << taposlinya;
    }
    kundi {
        clabas << "Hindi mo pinili ang letrang a" << taposlinya;
    }

    habang(totoo) {
        doble numero = 0.0;
        clabas << "Magtala ng isang numero: ";
        cpasok >> numero;

        kung (numero != 5.2) {
            clabas << "Ang numero na " << numero << " ay mali!" << taposlinya;
            ituloy;
        }
        kundi {
            clabas << "Ang numero na " << numero << " ay tama!" << taposlinya;
            sirain;
        }


    }


    balik 0;
}