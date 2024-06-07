import React, { useState } from 'react';
import { View, StyleSheet } from 'react-native';
import EmployeeList from '../components/EmployeeList';
import SearchBar from '../components/SearchBar';
// import { data } from '../constants/Tables';

const data = [
  { firstName: 'Audric', lastName: 'Carignan', imageUrl: 'https://randomuser.me/api/portraits/men/1.jpg' },
  { firstName: 'Valentine', lastName: 'Allard', imageUrl: 'https://randomuser.me/api/portraits/women/11.jpg' },
  { firstName: 'Étienne', lastName: 'Bériault', imageUrl: 'https://randomuser.me/api/portraits/men/3.jpg' },
  { firstName: 'Aurélie', lastName: 'Dupont', imageUrl: 'https://randomuser.me/api/portraits/women/12.jpg' },
  { firstName: 'Lucas', lastName: 'Gagnon', imageUrl: 'https://randomuser.me/api/portraits/men/5.jpg' },
  { firstName: 'Clara', lastName: 'Martin', imageUrl: 'https://randomuser.me/api/portraits/women/14.jpg' },
  { firstName: 'Maxime', lastName: 'Lefebvre', imageUrl: 'https://randomuser.me/api/portraits/men/7.jpg' },
  { firstName: 'Camille', lastName: 'Dubois', imageUrl: 'https://randomuser.me/api/portraits/women/16.jpg' },
  { firstName: 'Gabriel', lastName: 'Moreau', imageUrl: 'https://randomuser.me/api/portraits/men/9.jpg' },
  { firstName: 'Léa', lastName: 'Lavoie', imageUrl: 'https://randomuser.me/api/portraits/women/18.jpg' },
];

export default function HomeScreen() {
  const [dataSearch, setDataSearch] = useState(data);

  const handleSearch = (searchText) => {
    if (searchText.trim() === '') {
      // If search input is empty, reset dataSearch to the original data
      setDataSearch(data);
    } else {
      // Filter data based on the search input
      const filteredData = data.filter((item) =>
        item.firstName.toLowerCase().includes(searchText.toLowerCase())
      );

      setDataSearch(filteredData);
    }
  };

  return (
    <View style={styles.container}>
      <EmployeeList data={dataSearch}/>
      <SearchBar onSearch={handleSearch}/>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
  },
});