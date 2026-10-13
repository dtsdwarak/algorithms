class Solution {
public:

    unordered_set<string> unique_emails;

    string processEmailAddress(string email) {
        
        int i=0;
        string processed_email;

        for(; (email[i] != '+' && email[i] != '@'); i++) {
            
            if (email[i] == '.')
                continue;
            processed_email += email[i];
        }

        // copy @domain.com to processed_email
        processed_email += email.substr(email.find('@'));
        
        return processed_email;
    }

    int numUniqueEmails(vector<string>& emails) {

        for(string email: emails) {
            string processed_email = processEmailAddress(email);
            if (unique_emails.count(processed_email) == 0)
                unique_emails.insert(processed_email);
        }

        return unique_emails.size();

    }
};
