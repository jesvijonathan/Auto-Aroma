namespace boost
{
    namespace filesystem
    {
        class path;

        void swap(path& lhs, path& rhs);
        bool lexicographical_compare(path::iterator first1, path::iterator last1,
            path::iterator first2, path::iterator last2);

        bool operator==(const path& lhs, const path& rhs);
        bool operator!=(const path& lhs, const path& rhs);
        bool operator< (const path& lhs, const path& rhs);
        bool operator<=(const path& lhs, const path& rhs);
        bool operator> (const path& lhs, const path& rhs);
        bool operator>=(const path& lhs, const path& rhs);

        path operator/ (const path& lhs, const path& rhs);

        std::ostream& operator<<(std::ostream& os, const path& p);
        std::wostream& operator<<(std::wostream& os, const path& p);
        std::istream& operator>>(std::istream& is, path& p);
        std::wistream& operator>>(std::wistream& is, path& p)

            class filesystem_error;

        class directory_entry;

        class directory_iterator;

        class recursive_directory_iterator;

        enum file_type {
            status_error, file_not_found, regular_file, directory_file,
            symlink_file, block_file, character_file, fifo_file, socket_file,
            type_unknown
        };

        class file_status;

        struct space_info  // returned by space function
        {
            uintmax_t capacity;
            uintmax_t free;
            uintmax_t available; // free space available to a non-privileged process
        };

        BOOST_SCOPED_ENUM_START(copy_option)
        {
            fail_if_exists,
                overwrite_if_exists
        };
        BOOST_SCOPED_ENUM_END

            // operational functions

            path         absolute(const path& p, const path& base = current_path());

        void         copy(const path& from, const path& to);
        void         copy(const path& from, const path& to, system::error_code& ec);

        void         copy_directory(const path& from, const path& to);
        void         copy_directory(const path& from, const path& to, system::error_code& ec);

        void         copy_file(const path& from, const path& to);
        void         copy_file(const path& from, const path& to, system::error_code& ec);
        void         copy_file(const path& from, const path& to, BOOST_SCOPED_ENUM(copy_option) option);
        void         copy_file(const path& from, const path& to, BOOST_SCOPED_ENUM(copy_option) option,
            system::error_code& ec);

        void         copy_symlink(const path& existing_symlink, const path& new_symlink);
        void         copy_symlink(const path& existing_symlink, const path& new_symlink, system::error_code& ec);

        bool         create_directories(const path& p);
        bool         create_directories(const path& p, system::error_code& ec);

        bool         create_directory(const path& p);
        bool         create_directory(const path& p, system::error_code& ec);

        void         create_directory_symlink(const path& to, const path& new_symlink);
        void         create_directory_symlink(const path& to, const path& new_symlink, system::error_code& ec);

        void         create_hard_link(const path& to, const path& new_hard_link);
        void         create_hard_link(const path& to, const path& new_hard_link, system::error_code& ec);

        void         create_symlink(const path& to, const path& new_symlink);
        void         create_symlink(const path& to, const path& new_symlink, system::error_code& ec);

        path         current_path();
        path         current_path(system::error_code& ec);
        void         current_path(const path& p);
        void         current_path(const path& p, system::error_code& ec);

        bool         exists(file_status s);
        bool         exists(const path& p);
        bool         exists(const path& p, system::error_code& ec);

        bool         equivalent(const path& p1, const path& p2);
        bool         equivalent(const path& p1, const path& p2, system::error_code& ec);

        uintmax_t    file_size(const path& p);
        uintmax_t    file_size(const path& p, system::error_code& ec);
        uintmax_t    hard_link_count(const path& p);
        uintmax_t    hard_link_count(const path& p, system::error_code& ec);

        bool         is_directory(file_status s);
        bool         is_directory(const path& p);
        bool         is_directory(const path& p, system::error_code& ec);

        bool         is_empty(const path& p);
        bool         is_empty(const path& p, system::error_code& ec);

        bool         is_other(file_status s);
        bool         is_other(const path& p, );
        bool         is_other(const path& p, system::error_code& ec);

        bool         is_regular_file(file_status s);
        bool         is_regular_file(const path& p);
        bool         is_regular_file(const path& p, system::error_code& ec);

        bool         is_symlink(file_status s);
        bool         is_symlink(const path& p);
        bool         is_symlink(const path& p, system::error_code& ec);

        std::time_t  last_write_time(const path& p);
        std::time_t  last_write_time(const path& p, system::error_code& ec);
        void         last_write_time(const path& p, const std::time_t new_time);
        void         last_write_time(const path& p, const std::time_t new_time, system::error_code& ec);

        path         read_symlink(const path& p);
        path         read_symlink(const path& p, system::error_code& ec);

        bool         remove(const path& p);
        bool         remove(const path& p, system::error_code& ec);

        uintmax_t    remove_all(const path& p);
        uintmax_t    remove_all(const path& p, system::error_code& ec);

        void         rename(const path& from, const path& to);
        void         rename(const path& from, const path& to, system::error_code& ec);

        void         resize_file(const path& p, uintmax_t size);
        void         resize_file(const path& p, uintmax_t size, system::error_code& ec);

        space_info   space(const path& p);
        space_info   space(const path& p, system::error_code& ec);

        file_status  status(const path& p);
        file_status  status(const path& p, system::error_code& ec);

        bool         status_known(file_status s);

        file_status  symlink_status(const path& p);
        file_status  symlink_status(const path& p, system::error_code& ec);

        path         system_complete(const path& p);
        path         system_complete(const path& p, system::error_code& ec);

        path         unique_path(const path& model = "%%%%-%%%%-%%%%-%%%%");
        path         unique_path(const path& model, system::error_code& ec);

    } // namespace filesystem
} // namespace boost