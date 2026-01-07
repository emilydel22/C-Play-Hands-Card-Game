#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* -------------------- Constants -------------------- */

#define NCARDS 52
#define NPROPS 2      /* face, suit */

#define NSUITS 4
#define NFACES 13

/* -------------------- Text labels -------------------- */

char* suit[] = { "hearts", "spades", "clubs", "diamonds" };

/* index 0 is "blank" so that Ace=1 and King=13 */
char* face[] = {
    "blank", "ace", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "jack", "queen", "king"
};

/* -------------------- Prototypes -------------------- */

int  PrintCard(int cards[][NPROPS], int i);   /* now returns play value */
void InitDeck(int deck[NCARDS][NPROPS]);
void SwapCards(int deck[NCARDS][NPROPS], int a, int b);
void ShuffleDeck(int deck[NCARDS][NPROPS]);
int  GetPlayValue(int cards[][NPROPS], int i);

/* -------------------- main -------------------- */

int main(void)
{
    int deck[NCARDS][NPROPS];
    int hand1[5][2], hand2[5][2];
    int play1 = 0, play2 = 0;
    int i, index1 = 0, index2 = 0;
    time_t rawtime = time(NULL);

    srand((unsigned int)time(NULL));

    /* Build fresh deck and shuffle */
    InitDeck(deck);
    ShuffleDeck(deck);

    /* Deal top 10 cards: even -> hand1, odd -> hand2 */
    for (i = 0; i < 10; i++)
    {
        if (i & 1)   /* odd -> hand2 */
        {
            hand2[index2][0] = deck[i][0];
            hand2[index2][1] = deck[i][1];
            index2++;
        }
        else         /* even -> hand1 */
        {
            hand1[index1][0] = deck[i][0];
            hand1[index1][1] = deck[i][1];
            index1++;
        }
    }

    /* Print hands and accumulate totals */
    printf("Hand1:\n");
    for (i = 0; i < 5; i++)
        play1 += PrintCard(hand1, i);
    printf("Total for Hand1 is: %d\n\n", play1);

    printf("Hand2:\n");
    for (i = 0; i < 5; i++)
        play2 += PrintCard(hand2, i);
    printf("Total for Hand2 is: %d\n\n", play2);

    /* Winner / tie */
    if (play1 == play2)
        printf("Result: They are Tied, deal again!\n");
    else if (play1 > play2)
        printf("Result: Hand1 is the winner!\n");
    else
        printf("Result: Hand2 is the winner!\n");

    /* Required timestamp line for screenshot */
    printf("Printed on %s", ctime(&rawtime));

    system("PAUSE");
    return 0;
}

/* -------------------- Functions -------------------- */

/* Print "<face> of <suit> (value N)" and return play value */
int PrintCard(int cards[][NPROPS], int i)
{
    int f = cards[i][0];   /* face index 1..13 */
    int s = cards[i][1];   /* suit index 0..3 */
    int val = GetPlayValue(cards, i);

    const char* ftxt = (f >= 0 && f <= NFACES) ? face[f] : "unknown";
    const char* stxt = (s >= 0 && s < NSUITS)  ? suit[s] : "unknown";

    printf("%s of %s (value %d)\n", ftxt, stxt, val);
    return val;
}

/* Fill deck with all 52 unique cards */
void InitDeck(int deck[NCARDS][NPROPS])
{
    int k = 0;
    for (int s = 0; s < NSUITS; s++)
    {
        for (int f = 1; f <= NFACES; f++)
        {
            deck[k][0] = f;   /* face */
            deck[k][1] = s;   /* suit */
            k++;
        }
    }
}

/* Swap two cards in the deck */
void SwapCards(int deck[NCARDS][NPROPS], int a, int b)
{
    if (a == b) return;

    int tf = deck[a][0], ts = deck[a][1];
    deck[a][0] = deck[b][0];
    deck[a][1] = deck[b][1];
    deck[b][0] = tf;
    deck[b][1] = ts;
}

/* Fisher–Yates shuffle */
void ShuffleDeck(int deck[NCARDS][NPROPS])
{
    for (int i = NCARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        SwapCards(deck, i, j);
    }
}

/* Ace = 1, 2–9 as is, 10/J/Q/K = 10 */
int GetPlayValue(int cards[][NPROPS], int i)
{
    int f = cards[i][0];
    return (f > 10) ? 10 : f;
}
