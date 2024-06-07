import {React} from 'react';
import { StyleSheet, View, Text, Image, Dimensions, TouchableOpacity } from 'react-native';
import Carousel from 'react-native-snap-carousel';
import { windowHeight, windowWidth } from '../constants/Dimensions';

const EmployeeList = ({ data }) => {

  const renderItem = ({ item, index }) => (
    <TouchableOpacity onPress={() => onProfileClick(index)}>
      <View style={styles.itemContainer}>
        <Image style={styles.profileImage} source={{ uri: item.imageUrl }}/>
        <Text style={styles.profileText}>{item.firstName}</Text>
      </View>
    </TouchableOpacity>
  );

  const onProfileClick = (index) => {
    console.log(data[index].firstName + ' ' + data[index].lastName);
  };

  return (
    <Carousel
      data={data}
      renderItem={renderItem}
      sliderWidth={windowWidth}
      itemWidth={110}
      layout={'default'}
      loop={false}
      inactiveSlideScale={1}
      inactiveSlideOpacity={1}
      enableMomentum={true}
      enableSnap={false}
      firstItem={0}
      activeSlideAlignment={'start'}
      contentContainerCustomStyle={styles.contentContainer}
    />
  );
};

const styles = StyleSheet.create({
  itemContainer: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'flex-start',
    top: windowHeight / 6,
  },

  profileImage: {
    width: 80,
    height: 80,
    borderRadius: 50,
    borderWidth: 2,
    borderColor: '#f1e0da',
  },

  profileText: {
    marginTop: 5,
    fontSize: 16,
    textAlign: 'center',
    height: 30,
    color: 'rgba(0, 0, 0, 0.5)',
    fontWeight: 'bold',
  },

  contentContainer: {
    paddingRight: -windowWidth,
  },
});

export default EmployeeList;