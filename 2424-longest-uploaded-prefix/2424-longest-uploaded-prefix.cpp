class LUPrefix {
private:
    vector<bool> uploaded;
    int longest_prefix;

public:
    LUPrefix(int n) {
        // Size n + 2 to safely handle 1-based indexing and boundary checks
        uploaded.resize(n + 2, false);
        longest_prefix = 0;
    }
    
    void upload(int video) {
        uploaded[video] = true;
        // Advance the prefix tracker as far as possible
        while (uploaded[longest_prefix + 1]) {
            longest_prefix++;
        }
    }
    
    int longest() {
        return longest_prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */