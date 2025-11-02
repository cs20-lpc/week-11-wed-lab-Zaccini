template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    int probes = 0;
    if (N >= M) {
        throw string("Hash table is full");
    }
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;
        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            N++;
            return probes;
        }
        if (table[idx] == key) {
            return probes;
        }
    }
    throw string("Hash table is full");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    int probes = 0;

    for (int i = 0; i < M; i++) {
        int index = probeIndex(key, i);
        probes++;
        
        if (!occupied[index]) {
            return pair<bool, int>(false, probes);
        }
        
        if (occupied[index] && table[index] == key) {
            return pair<bool, int>(true, probes);
        }
    }
    
    return pair<bool, int>(false, probes);
}
