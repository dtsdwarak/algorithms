# include <bits/stdc++.h>

using namespace std;

struct LogRecord {
  
  uint64_t txid;
  uint64_t page_id;
  uint64_t offset;
  string data;
    
};

class WriteAheadLog {

private:

    ofstream log_file_;
    mutex mutex_;
    
    void write_uint64(uint64_t value) 
    {
        log_file_.write(reinterpret_cast<const char*>(&value),sizeof(value));
    }
    
public:

    explicit WriteAheadLog(const string& path) 
    {
        log_file_.open(path, ios::binary|ios::app);
        if (!log_file_)
        {
            throw runtime_error("Cannot open WAL");
        }
    }
    
    void append(const LogRecord&);
    void flush();
    vector<LogRecord> recover();
    
};


void WriteAheadLog::append(const LogRecord& log) {
    
    lock_guard<mutex> lock(mutex_);
    
    write_uint64(log.txid);
    write_uint64(log.page_id);
    write_uint64(log.offset);
    write_uint64(log.data);
}

/** === Program Logic === **/

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
           
    return 0;
    
}
