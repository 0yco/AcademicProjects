CREATE DATABASE paul;
CREATE USER paul WITH ENCRYPTED PASSWORD 'democracyIsFragile';
GRANT CONNECT ON DATABASE paul TO paul;
GRANT USAGE ON SCHEMA public TO paul;
