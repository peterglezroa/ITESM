#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <cstring>

#define LIFES 4

using namespace std;

struct clan { int army; int number; };

void fill_stochastic(int size, int *m) {
    int current;
    for(int i = 0; i < size; i++) {
        current = 100;
        for(int j = 0; j < size-1; j++) {
            if(i != j) {
                m[j + i*size] = rand()%current;
                current -= m[j + i*size];
            } else {
                m[j + i*size] = 0;
            }
        }
        (i < (size-1))? m[(size+i*size)-1] += current: m[(size+i*size)-2]+=current;
    }
}

void scan_matrix(int size, int *m) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            scanf("%i ", &(m[j+i*size]));
    scanf("%*i");
}


bool validate_stochastic(int size, int *m) {
    int sum;
    for(int i = 0; i < size; i++) {
        sum = 0;
        for(int j = 0; j < size; j++)
            sum += m[j + i*size];
        if(sum != 100)
            return false;
    }
    return true;
}

void print_matrix(int size, int *m, FILE *stream) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            fprintf(stream, "%i ", m[j + i*size]);
        fprintf(stream, "\n");
    }
}

void status(int size, vector<clan> clans, FILE *stream) {
    for(auto clan : clans)
        fprintf(stream, "Clan %i - %i\n", clan.number, clan.army);
}

void simulate(FILE *stream, int size, bool interactive) {
    int *probs;
    int from, to, ran, sum, round = 1;
    vector<clan> clans;

    // Scan armies sizes
    if(interactive)
        printf("Give me the armies:\n");
    for(int i = 0; i < size; i++) {
        clans.push_back(clan({1, i}));
        (interactive)? scanf("%i", &(clans[i].army)) : clans[i].army = rand()%LIFES+1;
    }

    // Run simulation
    while(size > 1) {
        fprintf(stream, "ROUND %i\n", round);
        status(size, clans, stream);
        fprintf(stream, "\n");

        // Scan/Make probabilities
        probs = (int*)malloc(sizeof(int)*size*size);
        for(int i = 0; i<(size*size); i++)
            probs[i] = 0;
        if(interactive) {
            do {
                fprintf(stdout, "Give me the probabilities:\n");
                scan_matrix(size, probs);
                if(!validate_stochastic(size, probs))
                    fprintf(stderr, "Not a valid stochastic matrix!");
                else
                    break;
            } while(true);
        } else {
            fill_stochastic(size, probs);
        }
        fprintf(stream, "Probabilities:\n");
        print_matrix(size, probs, stream);

        // Attack until someone dies
        while(true) {
            from = rand()%size;
            ran = rand()%101;
            sum = 0;
            for(int i = 0; i < size; i++) {
                sum += probs[i+from*size];
                to = i;
                if(ran <= sum)
                    break;
            }
            fprintf(stream, "Clan %i attacks clan %i (%i)\n", clans.at(from).number, clans.at(to).number, ran);
            clans.at(to).army -= 1;
            if(clans.at(to).army <= 0) {
                fprintf(stream, "Clan %i died!\n", clans.at(to).number);
                clans.erase(clans.begin()+to);
                break;
            }
        }

        free(probs);
        size--;
        round++;
        fprintf(stream, "\n\n");
    }
    fprintf(stream, "\nClan %i wins!\n", clans[0].number);
}

void run(FILE *stream, int size, bool interactive) {
    // Declare matrices with defined size
}

void print_usage(char *file_name) {
    fprintf(stderr, "usage: %s <number of groups (>3)>\n", file_name);
    fprintf(stderr, "\n\t-o <path to output file>");
    fprintf(stderr, "\n\t-i <interactive mode>\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    // Init random
    srand(time(NULL));
    // Default values
    int n_groups = rand()%8+3;
    bool interactive = false;
    FILE *output=stdout;

    if(argc > 1) {
        // Scan for number of groups
        n_groups = atoi(argv[1]);
        if(n_groups < 3)
            print_usage(argv[0]);

        // Scan for flags
        for(int i = 2; i < argc; i++) {
            // Input file with stochastic matrix and army sizes
            if(strcmp(argv[i], "-o") == 0) {
                if((output = fopen(argv[i+1], "w")) == NULL)
                    fprintf(stderr, "Could not open file %s for writing", argv[i]);
                i++;
            // Interactive mode
            } else if(strcmp(argv[i], "-i") == 0) { interactive = true; }
        }
    } else { print_usage(argv[0]); }

    simulate(output, n_groups, interactive);
    return 0;
}
