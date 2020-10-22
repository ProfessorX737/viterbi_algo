/*
Exercise: In California there are twice as many raccoons as possums. Having gotten a job with Google, you
are in California observing a back yard. It is dusk, so the probability that you think you saw a raccoon when
you are actually looking at a possum at a distance is 1/3; the probability that you think you saw a possum while
you are actually looking at a raccoon at a distance is 1/4. Raccoons move in packs; so if a raccoon comes to
your back yard the probability that the next animal to follow will also be a raccoon is 4/5. Possums are solitary
animals, so if a possum comes to your back yard, this does not impact the probabilities what the next animal
to come will be (a possum or a raccoon, but recall in California there are twice as many raccoons as possums!)
You believe that you saw four animals coming in the following order: a raccoon, a possum, a possum, a raccoon
(rppr). Given such a sequence of observations, what actual sequence of animals is most likely to cause such a
sequence of your observations?

possum = 1
raccoon = 2

T = length of sequence of observables
K = size of set of all states
N = size of set of all observables

Input: 
- T,K,N
- Y: length T array of 'observables' i : 1 <= i <= N
- S: length K array of starting state probabilities
- P: K x K transition matrix
- E: K x N emission matrix that maps states --> observables

Output:
length T sequence of states j : 1 <= i <= K
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double ld;

int main() {

    int T,K,N;

    cin >> T >> K >> N;

    int Y[T+1] = {0};
    ld S[K+1] = {0};
    ld P[K+1][K+1] = {0};
    ld E[K+1][N+1] = {0};

    // read the sequence of T observables
    for(int i = 1; i <= T; i++) {
        cin >> Y[i];
    }

    // read the starting state probabilities
    for(int i = 1; i <= K; i++) {
        cin >> S[i];
    }

    // read the transition matrix
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= K; j++) {
            cin >> P[i][j];
        }
    }

    // read the emission matrix
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> E[i][j];
        }
    }

    ld dp[T+1][K+1] = {0};
    int from[T+1][K+1] = {0};

    // base case
    for(int k = 1; k <= K; k++) {
        dp[1][k] = S[k]*E[k][Y[1]];
    }

    // bottom up dp O(T*K^2)
    for(int i = 2; i <= T; i++) {
        for(int k = 1; k <= K; k++) {
            for(int m = 1; m <= K; m++) {
                ld temp = dp[i-1][m]*P[m][k]*E[k][Y[i]];
                if(dp[i][k] <= temp) {
                    dp[i][k] = temp;
                    from[i][k] = m;
                }
            }
        }
    }

    // find the ending state that gave max probability
    int tmax = 1;
    for(int m = 1; m <= K; m++) {
        if(dp[T][m] > dp[T][tmax]) tmax = m;
    }

    // The sequence of states most likely to cause the sequence of observables has probability:
    // cout << dp[T][tmax] << endl;

    int res[T+1] = {0};
    res[T] = tmax;

    // backtrack the states that gave best ending probability
    for(int i = T; i > 1; i--) {
        res[i-1] = from[i][res[i]];
    }

    for(int i = 1; i <= T; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}