## Viterbi Algorithm In a Competitive Programming Question Format

**Exercise**: In California there are twice as many raccoons as possums. Having gotten a job with Google, you
are in California observing a back yard. It is dusk, so the probability that you think you saw a raccoon when
you are actually looking at a possum at a distance is 1/3; the probability that you think you saw a possum while
you are actually looking at a raccoon at a distance is 1/4. Raccoons move in packs; so if a raccoon comes to
your back yard the probability that the next animal to follow will also be a raccoon is 4/5. Possums are solitary
animals, so if a possum comes to your back yard, this does not impact the probabilities what the next animal
to come will be (a possum or a raccoon, but recall in California there are twice as many raccoons as possums!)
You believe that you saw four animals coming in the following order: a raccoon, a possum, a possum, a raccoon
(2112). Given such a sequence of observations, what actual sequence of animals is most likely to cause such a
sequence of your observations?

possum = 1
raccoon = 2

T = length of sequence of observables
K = size of set of all states
N = size of set of all observables

Input: 
- T,K,N
- Y: length T array of 'observables' i (1 <= i <= N)
- S: length K array of starting state probabilities
- P: K x K transition matrix
- E: K x N emission matrix that maps states --> observables

Output:
length T sequence of states j (1 <= j <= K) most likely to cause the sequence Y