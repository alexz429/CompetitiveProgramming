    #include <bits/stdc++.h>
    int *vals;
    int main()
    {
        int max;
        scanf("%d", &max);
        vals = new int[max];
        for (int count = 0; count < max; count++)
        {
            scanf("%d", &vals[count]);
        }
        int best = 0;
        for (int i = 0; i < (1 << max); i++)
        {
            // printf("%d ", i);
            int size = 0;
            for (int count = 0; count < max; count++)
            {
                if ((i & 1 << count) != 0)
                {
                    size++;
                }
            }
            // printf("%d\n", size);
            if (size <= best)
                continue;
            int adds[10];
            std::fill(&adds[0], &adds[10], 0);
            bool good = true;
            for (int count = 0; count < max; count++)
            {

                if ((i & 1 << count) != 0)
                {
                    int offset=1;
                    for (int count2 = 0; count2 < 10; count2++)
                    {

                        adds[count2] += (vals[count]/offset) % 10;
                        // printf("%d\n", adds[count2]);
                        if (adds[count2] > 9)
                        {
                            good = false;
                            break;
                        }
                        offset*=10;
                    }
                }
                if (!good)
                    break;
            }
            if (good)
            {
                best = size;
            }
        }
        printf("output:%d", best);
    }