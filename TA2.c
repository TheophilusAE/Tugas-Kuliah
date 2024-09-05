#include <stdio.h>

double calculate_average(int *arr, int size) {
	int i;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    int T,i,t;
    scanf("%d", &T);

    for (t = 0; t < T; t++) {
        if (t > 0) {
            getchar();
        }

        int Ncs, Ne;
        scanf("%d %d", &Ncs, &Ne);

        int cs_students[Ncs];
        int econ_students[Ne];

        for (i = 0; i < Ncs; i++) {
            scanf("%d", &cs_students[i]);
        }

        for (i = 0; i < Ne; i++) {
            scanf("%d", &econ_students[i]);
        }

        double cs_avg = calculate_average(cs_students, Ncs);
        double econ_avg = calculate_average(econ_students, Ne);

        int count = 0;

        for (i = 0; i < Ncs; i++) {
            double new_cs_avg = (cs_avg * Ncs - cs_students[i]) / (Ncs - 1);
            double new_econ_avg = (econ_avg * Ne + cs_students[i]) / (Ne + 1);

            if (new_cs_avg > cs_avg && new_econ_avg > econ_avg) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
