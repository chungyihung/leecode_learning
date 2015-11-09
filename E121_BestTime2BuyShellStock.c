int max(int a, int b)
{
    return a > b? a : b;
}

int min(int a, int b)
{
    return a < b? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int i, maxprofit = 0;
    int cur_min = prices[0];

    if(pricesSize < 2)
        return 0;

    for (i = 0; i < pricesSize; i++)
    {
        maxprofit = max(maxprofit, prices[i] - cur_min);
        cur_min = min(cur_min, prices[i]);
    }

    return maxprofit;
}

#define stock_size 10
int main(int argc, char *argv[])
{
    int stock_record[stock_size] = {4,7,8,1,10,11,13,1,4,5};
    printf("max profit = %d\n", maxProfit(stock_record, stock_size));
    return 0;
}

